#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// Create data type
typedef struct sllist
{
    int value;
    struct sllist *next;
} node;

int main(void)
{
    // Creating the head of the list
    node *head = NULL;

    // Creating the list
    for (int i = 0; i < 3; i++)
    {
        // Creating the memory block
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Problems with malloc\n");
            return 1;
        }

        // Inserting the value and address at the n Node
        n->value = get_int("Value: ");
        n->next = NULL;

        // Checking if my list is empty
        if (head == NULL)
        {
            head = n;
        }

        // If not, loop again searching for the NULL (end of the list)
        else
        {
            for (node *ptr = head; ptr != NULL; ptr = ptr->next)
            {
                // If the last is found, append the new node to it
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    // Printing the current values
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->value);
        ptr = ptr->next;
    }

    // Removing the first value
    node *tmp = head->next;
    free(ptr);
    head = tmp;

    printf(":)\n");
    // Printinf the updated linked list
    ptr = head;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->value);
        ptr = ptr->next;
    }

    return 0;
}
