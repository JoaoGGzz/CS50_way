#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

// Criar estrutura de dados base para lista encadeada
typedef struct sllist
{
    int value;
    struct sllist *next;
} node;

// Começar a criar a lista
int main(void)
{
    // Criar head apontando para NULL, inicialmente
    node *head = NULL;

    // Criar a lista e inserir valores
    for (int i = 0; i < 3; i++)
    {
        // Criar espaço em memória para receber valores e endereço
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Problems to malloc\n");
            return 1;
        }

        // Inserir valores iniciais nos novos nodes criados
        n->value = get_int("Value: ");
        n->next = NULL;

        // Se a lista estiver vazia, atribua o primeiro node a ela
        if (head == NULL)
        {
            head = n;
        }

        // Se a lista já tiver valores, faça
        else
        {
            for (node *ptr = head; ptr != NULL; ptr = ptr->next)
            {
                // Se estou no final da lista
                if (ptr->next == NULL)
                {
                    // Adiciona o novo nó ao final
                    ptr->next = n;
                    break;
                }
            }
        }

    }

    // Print valores para confirmar
    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("Output: %i\n", ptr->value);
    }

    // Boa prática - Free nas variáveis
    node *ptr = head;
    while (ptr != NULL)
    {
        node *tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}
