// Create a queue using the singly list struct and do enqueue and dequeue operations
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// Single linked list struct
typedef struct _sllqueue
{
    int value;
    struct _sllqueue *next;
} sllqueue;

// Prototypes
void enqueue(sllqueue **head, sllqueue **tail, int v);
int dequeue(sllqueue **head, sllqueue **tail);
void print_queue(sllqueue *head, sllqueue *tail);

int main(void)
{
    // Initiating locating variables
    sllqueue *head = NULL;
    sllqueue *tail = NULL;

    // Looping to make the program more dynamic
    while(true)
    {
        // Receiving input from user
        int input = get_int("1 - Enqueue | 2 - Dequeue | 3 - Exit \nUser input: ");

        // Aesthetics
        printf("\n");

        // Enqueue operation condition
        if (input == 1)
        {
            // Receving the enqueue value from user
            int eq = get_int("Enqueue value: ");
            // Calling the enqueue function
            enqueue(&head, &tail, eq);
            // Printing the linked list elements
            print_queue(head, tail);
        }

        // Dequeue operation condition
        if (input == 2)
        {
            // Calling dequeue function and returning the value
            int dq = dequeue(&head, &tail);

            // Checking if the current linked list is empty, if so, return empty message and continue the looping
            if (dq == 0)
            {
                continue;
            }

            // If the dequeue was succesfull print dequeued value and printing the remaining linked list elements
            else
            {
                printf("Value dequeued: %i\n", dq);
                print_queue(head, tail);
            }
        }

        // Ending loop condition
        else if (input == 3)
        {
            printf("Program closed.\n\n");
            break;
        }
    }
}

// Adding elements on the singly linked list
void enqueue(sllqueue **head, sllqueue **tail, int v)
{
    // Creating the block of memory to add the new element
    sllqueue *q = malloc(sizeof(sllqueue));
    if (q == NULL)
    {
        printf("Can't malloc.\n");
        return;
    }

    // Adding the user's value
    q->value = v;

    // Standard NULL to next attribute
    q->next = NULL;

    // Special condition if the linked list is empty
    if (*head == NULL && *tail == NULL)
    {
        *head = q;
        *tail = q;
    }

    // If already has values, link the new element on the last of the linked list
    else
    {
        // Link the new created element to the old last element of the linked list
        (*tail)->next = q;

        // Update the last element
        *tail = q;
    }
}

// Removing the fist element of the linked list
int dequeue(sllqueue **head, sllqueue **tail)
{
    // Dealing with special condition: If the linked list is empty
    if (*head == NULL && *tail == NULL)
    {
        printf("Queue is empty.\n\n");
        return 0;
    }

    // Dealing with special condition: If the linked list has just one element
    else if ((*head)->next == NULL && *head != NULL && *tail != NULL)
    {
        // Storing the current element value on aux variable
        int v = (*head)->value;
        // Storing the current head location on aux variable
        sllqueue *tmp = *head;
        // Applying NULL to head
        *head = NULL;
        // Applying NULL to tail
        *tail = NULL;
        // Deleting the first (only) element
        free(tmp);
        // Returning the value deleted
        return v;
    }

    // Other possibilities
    else
    {
        // Storing the current element value on aux variable
        int v = (*head)->value;
        // Storing the current head location on aux variable
        sllqueue *tmp = *head;
        // Updating the current element to the next one
        *head = (*head)->next;
        // Deleting the first element
        free(tmp);
        // Returnin the value deleted
        return v;
    }
}

// Printing the values of linked list
void print_queue(sllqueue *head, sllqueue *tail)
{
    // Dealing with empty linked list
    if (head == NULL && tail == NULL)
    {
        printf("Queue is empty.\n\n");
        return;
    }

    // Always printing the first element, named Head
    printf("Head: %i \n", head->value);
    // Cat's jump to ensure printing the first element in previous comand line
    head = head->next;
    // Looping through the rest of the list
    while (head != NULL)
    {
        // First checking if the next element is the last one to not allow print it in this loop
        if (head->next == NULL)
        {
            break;
        }
        // Printing middle elements
        printf("Middle value: %i\n", head->value);
        // Updating the current element to allow the while loop works fine
        head = head->next;
    }
    // Always printing the last element, named Tail
    printf("Tail: %i \n", tail->value);

    printf("\n");
}

