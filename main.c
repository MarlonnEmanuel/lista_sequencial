#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

void menu() {
    printf("Painel de Comando:\n");
    printf("1. Criar Lista\n");
    printf("2. Inserir Elemento\n");
    printf("3. Modificar Elemento\n");
    printf("4. Retirar Elemento\n");
    printf("5. Imprimir Lista\n");
    printf("6. Encerrar\n");
}

int main() {
    ListaSequencial* lista = NULL;
    int opcao, capacidade, posicao, valor;
    
    while (1) {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                if (lista != NULL) {
                    printf("Lista ja criada!\n");
                } else {
                    printf("Digite a capacidade da lista: ");
                    scanf("%d", &capacidade);
                    lista = criar_lista(capacidade);
                    printf("Lista criada com sucesso!\n");
                }
                break;
            case 2:
                if (lista == NULL) {
                    printf("Crie a lista primeiro!\n");
                } else {
                    printf("Digite a posicao para inserir (1 a %d): ", lista->quantidade + 1);
                    scanf("%d", &posicao);
                    printf("Digite o valor a ser inserido: ");
                    scanf("%d", &valor);
                    inserir_elemento(lista, posicao, valor);
                    printf("Elemento inserido com sucesso!\n");
                    imprimir_lista(lista);
                }
                break;
            case 3:
                if (lista == NULL) {
                    printf("Crie a lista primeiro!\n");
                } else {
                    printf("Digite a posicao para modificar (1 a %d): ", lista->quantidade);
                    scanf("%d", &posicao);
                    printf("Digite o novo valor: ");
                    scanf("%d", &valor);
                    modificar_elemento(lista, posicao, valor);
                    printf("Elemento modificado com sucesso!\n");
                    imprimir_lista(lista);
                }
                break;
            case 4:
                if (lista == NULL) {
                    printf("Crie a lista primeiro!\n");
                } else {
                    printf("Digite a posicao para retirar (1 a %d): ", lista->quantidade);
                    scanf("%d", &posicao);
                    valor = retirar_elemento(lista, posicao);
                    printf("Elemento retirado: %d\n", valor);
                    imprimir_lista(lista);
                }
                break;
            case 5:
                if (lista == NULL) {
                    printf("Crie a lista primeiro!\n");
                } else {
                    imprimir_lista(lista);
                }
                break;
            case 6:
                printf("Encerrando...\n");
                if (lista != NULL) {
                    free(lista->vetor);
                    free(lista);
                }
                exit(0);
            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}