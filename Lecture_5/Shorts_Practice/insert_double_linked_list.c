#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// Create linked list struct
typedef struct dllist
{
    int value;
    struct dllist *prev;
    struct dllist *next;
} node;

// Functions prototypes
node *insert(node *list_head, int number);

int main(void)
{
    // Create the list_header to keep track of the list beginning
    node *list_head = NULL;

    // Iterate to create and populate it
    for (int i = 0; i < 4; i++)
    {
        // Create the block of memory
        node *n = malloc(sizeof(node));
        // Check if was successfull
        if (n == NULL)
        {
            printf("Can't malloc\n");
            return 1;
        }
        // Populate the new node with value and address
        n->value = get_int("Value: ");
        n->prev = NULL;
        n->next = NULL;

        // Ensure the list_head
        // Check if it's empty
        if (list_head == NULL)
        {
            list_head = n;
        }

        else
        {
            node *ptr = list_head;
            ptr->prev = n;
            n->next = ptr;
            list_head = n;
        }

    }

    list_head = insert(list_head, 12);

    if (list_head == NULL)
    {
        printf("Can't malloc\n");
        return 1;
    }

    // Print the whole list left to right
    node *ptr = list_head;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->value);
        ptr = ptr->next;
    }

    // Print the whole list right to left
    ptr = list_head;
    while (ptr != NULL)
    {
        if (ptr->next == NULL)
        {
            node *ptr2 = ptr;
            while (ptr2 != NULL)
            {
                printf("%i\n", ptr2->value);
                ptr2 = ptr2->prev;
            }
        }
        ptr = ptr->next;
    }

    return 0;
    // Free all list
}

// Create a function to insert a new node into the beginning of that list
node *insert(node *list_head, int number)
{
    // Create the block of memory
    node *block_memory = malloc(sizeof(node));
    // Check if was successfull
    if (block_memory == NULL)
    {
        printf("Can't malloc\n");
        return NULL;
    }
    // Assign to the new node the number value and next/prev references
    block_memory->value = number;
    block_memory->prev = NULL;
    block_memory->next = NULL;

    if (list_head == NULL)
    {
        return list_head = block_memory;
    }

    else
    {
        node *aux = list_head;
        // Assign the old first node prev attribute to the new node
        aux->prev = block_memory;
        block_memory->next = aux;


    }
    // Change the list_head to the new node position
    return list_head = block_memory;
}

// Print the whole list left to right and left to right
    // node *ptr = list_head;
    // while(ptr != NULL)
    // {
    //     printf("%i\n", ptr->value);

    //     if (ptr->next == NULL)
    //     {
    //         node *ptr2 = ptr;
    //         while (ptr2 != NULL)
    //         {
    //             printf("%i\n", ptr2->value);
    //             ptr2 = ptr2->prev;
    //         }
    //     }

    //     ptr = ptr->next;
    // }
