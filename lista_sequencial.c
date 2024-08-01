#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

ListaSequencial* criar_lista(int capacidade) {
    ListaSequencial* lista = (ListaSequencial*) malloc(sizeof(ListaSequencial));
    lista->vetor = (int*) malloc(capacidade * sizeof(int));
    lista->quantidade = 0;
    lista->capacidade = capacidade;
    return lista;
}

int lista_vazia(ListaSequencial* lista) {
    return lista->quantidade == 0;
}

int lista_cheia(ListaSequencial* lista) {
    return lista->quantidade == lista->capacidade;
}

int tamanho_lista(ListaSequencial* lista) {
    return lista->quantidade;
}

int obter_elemento(ListaSequencial* lista, int posicao) {
    if (posicao < 1 || posicao > lista->quantidade) {
        printf("Posição inválida\n");
        exit(1);
    }
    return lista->vetor[posicao - 1];
}

void inserir_elemento(ListaSequencial* lista, int posicao, int valor) {
    if (lista_cheia(lista)) {
        printf("Lista cheia!\n");
        exit(1);
    }
    if ((posicao < 1 || posicao > lista->quantidade + 1) || (posicao > lista->capacidade)) {
        printf("Posição inválida\n");
        exit(1);
    }
    for (int i = lista->quantidade; i >= posicao; i--) {
        lista->vetor[i] = lista->vetor[i - 1];
    }
    lista->vetor[posicao - 1] = valor;
    lista->quantidade++;
}

void modificar_elemento(ListaSequencial* lista, int posicao, int valor) {
    if (posicao < 1 || posicao > lista->quantidade) {
        printf("Posição inválida\n");
        exit(1);
    }
    lista->vetor[posicao - 1] = valor;
}

int retirar_elemento(ListaSequencial* lista, int posicao) {
    if (posicao < 1 || posicao > lista->quantidade) {
        printf("Posição inválida\n");
        exit(1);
    }
    int valor = lista->vetor[posicao - 1];
    for (int i = posicao - 1; i < lista->quantidade - 1; i++) {
        lista->vetor[i] = lista->vetor[i + 1];
    }
    lista->quantidade--;
    return valor;
}

void imprimir_lista(ListaSequencial* lista) {
    for (int i = 0; i < lista->quantidade; i++) {
        printf("|%d|", lista->vetor[i]);
    }
    printf("\n");
}
