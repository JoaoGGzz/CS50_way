// Incluir bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// Criar estrutura de listas
typedef struct sllist
{
    int value;
    struct sllist *next;
} node;

// Criar a lista
int main(void)
{
    // Criar head da lista
    node *list_head = NULL;

    // Iterar para criar a lista
    for (int i = 0; i < 3; i++)
    {
        // Criar espaço de memória
        node *n = malloc(sizeof(node));
        // Verificar se foi criada corretamente
        if (n == NULL)
        {
            printf("Can't malloc.\n");
            return 1;
        }
        // Inserir valor e endereço inicial
        n->value = get_int("Value: ");
        n->next = NULL;

        // Verificar se a lista está vazia (Primeiro caso)
        if (list_head == NULL)
        {
            list_head = n;
        }

        // Inserir novo valor no final da lista (Para treinar)
        else
        {
            for (node *ptr = list_head; ptr != NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
            }
        }
    }
    // Printar lista
    printf("Lista criada: ");
    node *ptr = list_head;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->value);
        ptr = ptr->next;
    }

    // Liberar todos os valores
    while (list_head != NULL)
    {
        if (list_head->next == NULL)
        {
            free(ptr);
            printf("List is over!\n");
        }
        node *tmp = list_head->next;
        free(list_head);
        list_head = tmp;
    }

    // Printar lista liberada (Para confirmar)
    ptr = list_head;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->value);
        if (ptr == NULL)
        {
            printf("List is over!\n");
        }
        ptr = ptr->next;
    }

    printf("The end!\n ");
    return 0;
}


