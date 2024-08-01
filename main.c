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
    printf("6. Verificar se a Lista está Vazia\n");
    printf("7. Verificar se a Lista está Cheia\n");
    printf("8. Obter Tamanho da Lista\n");
    printf("9. Encerrar\n");
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
                    printf("Lista já criada!\n");
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
                    printf("Digite a posição para inserir (1 a %d): ", lista->quantidade + 1);
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
                    printf("Digite a posição para modificar (1 a %d): ", lista->quantidade);
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
                    printf("Digite a posição para retirar (1 a %d): ", lista->quantidade);
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
                if (lista == NULL) {
                    printf("Crie a lista primeiro!\n");
                } else {
                    if (lista_vazia(lista)) {
                        printf("A lista está vazia.\n");
                    } else {
                        printf("A lista não está vazia.\n");
                    }
                }
                break;
            case 7:
                if (lista == NULL) {
                    printf("Crie a lista primeiro!\n");
                } else {
                    if (lista_cheia(lista)) {
                        printf("A lista está cheia.\n");
                    } else {
                        printf("A lista não está cheia.\n");
                    }
                }
                break;
            case 8:
                if (lista == NULL) {
                    printf("Crie a lista primeiro!\n");
                } else {
                    printf("Tamanho da lista: %d\n", tamanho_lista(lista)); // Nova opção para obter tamanho
                }
                break;
            case 9:
                printf("Encerrando...\n");
                if (lista != NULL) {
                    free(lista->vetor);
                    free(lista);
                }
                exit(0);
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}
