/*
 Função:
 Autor: Aderbal Ferreira da Silva Filho
 Data: 05/06/2024
 Observações: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char nome[100];
    int quantidade;
    struct Item *proximo;
} Item;

Item* criarItem(char *nome, int quantidade) {
    Item *novoItem = (Item *)malloc(sizeof(Item));
    strcpy(novoItem->nome, nome);
    novoItem->quantidade = quantidade;
    novoItem->proximo = NULL;
    return novoItem;
}

void inserirItem(Item **cabeca, char *nome, int quantidade) {
    Item *novoItem = criarItem(nome, quantidade);
    novoItem->proximo = *cabeca;
    *cabeca = novoItem;
}

void removerItem(Item **cabeca, char *nome) {
    Item *atual = *cabeca;
    Item *anterior = NULL;

    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Item '%s' nao encontrado na lista.\n", nome);
        return;
    }

    if (anterior == NULL) {
        *cabeca = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    printf("Item '%s' removido da lista.\n", nome);
}

void consultarItem(Item *cabeca, char *nome) {
    Item *atual = cabeca;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            printf("Item encontrado: %s, Quantidade: %d\n", atual->nome, atual->quantidade);
            return;
        }
        atual = atual->proximo;
    }

    printf("Item '%s' nao encontrado na lista.\n", nome);
}

void mostrarLista(Item *cabeca) {
    if (cabeca == NULL) {
        printf("A lista de compras esta vazia.\n");
        return;
    }

    Item *atual = cabeca;
    while (atual != NULL) {
        printf("Item: %s, Quantidade: %d\n", atual->nome, atual->quantidade);
        atual = atual->proximo;
    }
}

void limparLista(Item **cabeca) {
    Item *atual = *cabeca;
    while (atual != NULL) {
        Item *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    *cabeca = NULL;
    printf("Lista de compras limpa.\n");
}

int main() {
    Item *lista = NULL;
    int opcao;
    char nome[100];
    int quantidade;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Consultar item\n");
        printf("4. Mostrar todos os itens\n");
        printf("5. Limpar lista de compras\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do item: ");
                getchar();
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Digite a quantidade: ");
                scanf("%d", &quantidade);

                inserirItem(&lista, nome, quantidade);
                printf("Item inserido.\n");
                break;

            case 2:
                printf("Digite o nome do item a ser removido: ");
                getchar();
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                removerItem(&lista, nome);
                break;

            case 3:
                printf("Digite o nome do item a ser consultado: ");
                getchar();
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                consultarItem(lista, nome);
                break;

            case 4:
                mostrarLista(lista);
                break;

            case 5:
                limparLista(&lista);
                break;

            case 6:
                printf("Fim\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 6);

    return 0;
}
