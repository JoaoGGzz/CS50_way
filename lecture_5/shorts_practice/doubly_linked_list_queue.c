#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// Struct to allow the doubly linked list exist
typedef struct _dllqueue
{
    int value;
    struct _dllqueue *prev;
    struct _dllqueue *next;
} dllqueue;

// Functions prototypes
void enqueue(dllqueue **head, dllqueue **tail, int enqueue_variable);
bool dequeue(dllqueue **head, dllqueue **tail, int *out_value);
void print_queue(dllqueue *head);

int main(void)
{
    // Declaring the process variables
    dllqueue *head = NULL;
    dllqueue *tail = NULL;
    int v = 0;

    // Looping the program's dynamic
    while (true)
    {
        // Getting the user's choose
        int looping_variable = get_int("\n1 - Enqueue | 2 - Dequeue | 3 - Exit \nUser input: ");

        // Enqueue operation
        if (looping_variable == 1)
        {
            // Getting the enqueue value from user
            int enqueue_variable = get_int("Enqueue variable: ");

            // Calling enqueue function
            enqueue(&head, &tail, enqueue_variable);

            // Printing the current queue values
            print_queue(head);
        }

        // Dequeue operation
        else if (looping_variable == 2)
        {
            // Checking if dequeue was sucessfull using bool status return
            if (!dequeue(&head, &tail, &v))
            {
                printf("\nQueue is empty.\n");
            }

            // If was sucessfull print dequeued value and the new queue remaining values
            else
            {
                printf("Value dequeued: %i\n", v);
                print_queue(head);
            }
        }

        // Exit option
        else if (looping_variable == 3)
        {
            printf("\nProgram closed.\n");
            break;
        }
    }
}

// Enqueue function
void enqueue(dllqueue **head, dllqueue **tail, int enqueue_variable)
{
    // Creating the dynamic block of memory to grow the queue
    dllqueue *q = malloc(sizeof(dllqueue));
    if (q == NULL)
    {
        printf("Can't malloc.\n");
        return;
    }

    // Applying the user's value
    q->value = enqueue_variable;
    // Null standard values
    q->next = NULL;
    q->prev = NULL;

    // Special condition: If queue is empty
    if (*head == NULL)
    {
        *head = q;
        *tail = q;
    }

    // Another cases
    else
    {
        // Inserting the new element at the end of the queue by linking the former last element to the new last element (q)
        q->prev = *tail;
        (*tail)->next = q;
        *tail = q;
    }
}

// Dequeue function
bool dequeue(dllqueue **head, dllqueue **tail, int *out_value)
{
    // Creating an aux doubly linked list variable
    dllqueue *tmp = NULL;

    // Special condition: Dealing with empty queue
    if (*head == NULL)
    {
        return false;
    }

    // Special condition: Queue with just one element to dequeue
    else if ((*head)->next == NULL)
    {
        // Storing the header of queue
        tmp = *head;

        // Storing it's value to the out_value variable
        *out_value = (*head)->value;

        // Ensuring the right head and tail pointers direction
        *head = NULL;
        *tail = NULL;

        // Liberating the old node
        free(tmp);

        // Sinalizing sucessfull dequeue operation
        return true;
    }

    // Deleting anothers elements
    else
    {
        // Storing the next element
        tmp = (*head)->next;

        // Storing the current node value to the out_value variable
        *out_value = (*head)->value;

        // Liberating the current node
        free(*head);

        // Updating the header to the next node
        *head = tmp;

        // Updating the prev pointer to null
        (*head)->prev = NULL;

        // Sinalizing sucessfull dequeue operation
        return true;
    }
}

// Printing queue function
void print_queue(dllqueue *head)
{
    // Special condition: If queue is empty
    if (head == NULL)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    // Formating to show the header always
    printf("\nHead: %i \n", head->value);

    // Cat's jump to ensure it
    head = head->next;

    // Looping while we don't get to the end
    while (head != NULL)
    {
        // Just showing the tail if it exists, if not, show just the head
        if (head->next == NULL)
        {
            printf("Tail: %i \n", head->value);
            break;
        }

        // Middle values
        printf("Middle: %i \n", head->value);
        head = head->next;
    }
}
