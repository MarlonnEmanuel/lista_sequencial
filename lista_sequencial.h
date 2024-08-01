#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#define CAPACIDADE_MAX 100

typedef struct {
    int *vetor;
    int quantidade;
    int capacidade;
} ListaSequencial;

ListaSequencial* criar_lista(int capacidade);
int lista_vazia(ListaSequencial* lista);
int lista_cheia(ListaSequencial* lista);
int tamanho_lista(ListaSequencial* lista);
int obter_elemento(ListaSequencial* lista, int posicao);
void inserir_elemento(ListaSequencial* lista, int posicao, int valor);
void modificar_elemento(ListaSequencial* lista, int posicao, int valor);
int retirar_elemento(ListaSequencial* lista, int posicao);
void imprimir_lista(ListaSequencial* lista);

#endif
