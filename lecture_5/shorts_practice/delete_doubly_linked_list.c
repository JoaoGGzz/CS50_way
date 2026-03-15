#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// Struct to allow linked list
typedef struct dllist
{
    int value;
    struct dllist *prev;
    struct dllist *next;
} node;

// Prototype
void delete_node(node **list_header, node *target);

int main(void)
{
    // Create the header of the list
    node *list = NULL;

    // Iterating to create the doubly linked list
    for (int i = 0; i < 5; i++)
    {
        // Creating the block of memory and check
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Can't malloc\n");
            return 1;
        }

        // Receiving the input from the user
        n->value = get_int("Value: ");

        // Applying NULL to the linked list pointers
        n->prev = NULL;
        n->next = NULL;

        // If the list is empty
        if (list == NULL)
        {
            list = n;
        }

        // Adding the new node to the beggining of the list
        else
        {
            // Applying the address of the new node to the prev pointer of existing node
            list->prev = n;
            // Applying the list header to the next pointer of the current created node
            n->next = list;
            // Updating the list header to the new node recent added
            list = n;
        }
    }

    // Printing whole list (Left-right)
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->value);
        ptr = ptr->next;
    }

    // Receive from user the target value
    int target = get_int("Target: ");

    // Iterate through the list to search for the target
    ptr = list;
    while(ptr != NULL)
    {
        // If find the target number
        if (ptr->value == target)
        {
            // Call Delete Node function
            delete_node(&list, ptr);
            printf("Found!\n");
            // We are looking just for one time
            break;

        }
        // Updating the pointer next to allow moving through the linked list
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Not found!\n");
    }

    // Printing whole list (Left-right)
    ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->value);
        ptr = ptr->next;
    }

}

// Deleting node function
void delete_node(node **list_header, node *target)
{
    // First node delete condition
    if (target->prev == NULL && target->next != NULL)
    {
        target->next->prev = NULL;
        *list_header = target->next;
        free(target);
    }

    // Last node delete condition
    else if (target->next == NULL && target->prev != NULL)
    {
        target->prev->next = NULL;
        free (target);
    }

    // Only one single node delete condition
    else if (target->prev == NULL && target->next == NULL)
    {
        *list_header = NULL;
        free(target);
    }

    // Middle nodes delete condition
    else
    {
        // Assign the value of current.next to the previous.next node
        target->prev->next = target->next;

        // Assign the value of current.prev to the proximate.prev node
        target->next->prev = target->prev;

        // Free the current node
        free(target);
    }
}
