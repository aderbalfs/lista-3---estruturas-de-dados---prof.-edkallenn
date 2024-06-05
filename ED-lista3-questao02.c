/*
 Função:
 Autor: Aderbal Ferreira da Silva Filho
 Data: 05/06/2024
 Observações: 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float value;
    struct Node* next;
} Node;

Node* createNode(float value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->value = value;
        newNode->next = NULL;
    }
    return newNode;
}

void push(Node** top, float value) {
    Node* newNode = createNode(value);
    if (newNode != NULL) {
        newNode->next = *top;
        *top = newNode;
    } else {
        printf("Erro ao alocar memória para o novo nó.\n");
    }
}

void pop(Node** top) {
    if (*top == NULL) {
        printf("A pilha está vazia.\n");
        return;
    }
    Node* temp = *top;
    *top = (*top)->next;
    printf("Elemento removido: %.2f\n", temp->value);
    free(temp);
}

int isEmpty(Node* top) {
    return top == NULL;
}

void displayStack(Node* top) {
    if (isEmpty(top)) {
        printf("A pilha está vazia.\n");
        return;
    }
    printf("Elementos na pilha:\n");
    Node* current = top;
    while (current != NULL) {
        printf("%.2f\n", current->value);
        current = current->next;
    }
}

int main() {
    Node* top = NULL;
    int option;
    float value;

    do {
        printf("\nMenu\n");
        printf("1. Inserir (push)\n");
        printf("2. Retirar (pop)\n");
        printf("3. Verificar se a pilha está vazia\n");
        printf("4. Exibir a pilha\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Entre com o valor a ser inserido: ");
                scanf("%f", &value);
                push(&top, value);
                displayStack(top);
                break;
            case 2:
                pop(&top);
                displayStack(top);
                break;
            case 3:
                if (isEmpty(top)) {
                    printf("A pilha está vazia.\n");
                } else {
                    printf("A pilha não está vazia.\n");
                }
                break;
            case 4:
                displayStack(top);
                break;
            case 0:
                printf("Fim\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (option != 0);

    while (top != NULL) {
        Node* temp = top;
        top = top->next;
        free(temp);
    }

    return 0;
}
