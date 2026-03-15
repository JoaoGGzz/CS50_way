// CREATE A QUEUE BASED IN ARRAY, MAKE THE ENQUEUE AND DEQUEUE OPERATIONS
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// Defining global usefull variable
#define CAPACITY 5

// Declaring the queue struct
typedef struct _queue
{
    int array[CAPACITY];
    int front;
    int size;
} queue;

// Prototypes
void enqueue(queue *q, int value);
int dequeue(queue *q);
void print_array(queue *q);

int main(void)
{
    // Declaring the variables
    queue q;
    q.front = 0;
    q.size = 0;

    // Looping to create the queue by receving the input from user
    for (int i = 0; i < 5; i++)
    {
        int user_input = get_int("Enqueue: ");
        enqueue(&q, user_input);
    }

    // Testing some conditions or situations
    int p = dequeue(&q);
    printf("Dequeued: %i\n", p);
    print_array(&q);

    p = dequeue(&q);
    printf("Dequeued: %i\n", p);
    print_array(&q);

    p = dequeue(&q);
    printf("Dequeued: %i\n", p);
    print_array(&q);

    int user_input = get_int("Enqueue: ");
    enqueue(&q, user_input);

    user_input = get_int("Enqueue: ");
    enqueue(&q, user_input);

    user_input = get_int("Enqueue: ");
    enqueue(&q, user_input);

    user_input = get_int("Enqueue: ");
    enqueue(&q, user_input);

    print_array(&q);
}

// Enqueue operation
void enqueue(queue *q, int value)
{
    // Checking if my array is full
    if (q->size == CAPACITY)
    {
        printf("Array is full\n");
        return;
    }

    // Calculus to ensure the circular indexing proccess
    int index = (q->front + q->size) % CAPACITY;
    q->array[index] = value;

    // Adding the size variable to help track of filling the array
    q->size++;
}

// Dequeue operation
int dequeue(queue *q)
{
    // Checking if the array is empty
    if (q->size == 0)
    {
        printf("Array is empty\n");
        return 1;
    }

    // Store the value to return at end of this function
    int x = q->array[q->front];

    // Calculating the new index with circular behavior
    q->front = (q->front + 1) % CAPACITY;

    // Subtracting the size variable to ensure emptying array process
    q->size--;

    // Return the variable dequeued
    return x;
}

// Printing function respecting the queue current order
void print_array(queue *q)
{
    // Looping through all current array size
    for (int k = 0; k < q->size; k++)
    {
        // Calculating the correct current index with circular behavior
        int index = (q->front + k) % CAPACITY;

        // Printing the current correct element
        printf("%i\n", q->array[index]);
    }
}

// AFTER MISSIONS ARE TO CREATE SINGLY LINKED LIST QUEUE AND DO THE ENQUEUE AND DEQUEUE OPERATIONS
// AND AFTER CREATE DOUBLY LINKED LIST QUEUE AND DO THE ENQUEUE AND DEQUEUE OPERATIONS
