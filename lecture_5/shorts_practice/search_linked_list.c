#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// Declaring the linked list struct
typedef struct sllist
{
    int value;
    struct sllist *next;
} node;

// Prototype
bool search(node *list, int target);

int main(void)
{
    // List head to always find the beginning of the linked list
    node *list = NULL;

    // Looping to create a list with 3 inputs manually by user
    for (int i = 0; i < 3; i++)
    {
        // Creating the block of memory to store the data type that will store the next address and value
        node *n = malloc(sizeof(node));

        // Checking if the block were be able to create
        if (n == NULL)
        {
            printf("Fail to create block of memory\n");
            return 1;
        }

        // Receiving the input number from user
        n->value = get_int("Number: ");

        // Applying NULL for the current block just for security
        n->next = NULL;

        // Updating the head of the linked list
        n->next = list;
        list = n;
    }

    // Printing the values to answer the questions of first exercice
    // Never mess with the original head address, always create an aux variable to make others things
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->value);
        ptr = ptr->next;
    }

    // Running the search function
    if (search(list, 10) == true)
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not found!\n");
    }

    // Good practice to free the blocks of memory created before
    ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return 0;
}


// List search function (Iterative way)
bool search(node *list, int target)
{
    // Security copy of head
    node *head = list;

    // Looping on it
    while (head != NULL)
    {
        // Checking the value
        if (head->value == target)
        {
            return true;
        }

        // Updating the reference to another loop check
        head = head->next;
    }

    return false;
}


// List search function (Recursive way)
bool search(node *list, int target)
{
    // Security copy of head
    node *head = list;

    // Base case 1: List over
    if (head == NULL)
    {
        return false;
    }

    // Base case 2: Found number
    if (head->value == target)
    {
        return true;
    }

    // Recurssive step: Search the rest
    return search(head->next, target);

}
