#include <stdio.h>
#include <cs50.h>

const int CAPACITY = 5;

typedef struct _stack
{
    int array[CAPACITY];
    int top;
} stack;

void push_stack(stack *input_stack, int input);
int pop(stack *input_stack);
void print_array(stack *input_stack);

int main(void)
{
    stack s;
    s.top = 0;

    for (int i = 0; i < CAPACITY; i++)
    {
        int input_to_push = get_int("Value: ");
        push_stack(&s, input_to_push);
    }

    int pop_return = pop(&s);
    printf("Value popped: %i\n", pop_return);

    print_array(&s);

    pop_return = pop(&s);
    printf("Value popped: %i\n", pop_return);

    print_array(&s);
}

void push_stack(stack *input_stack, int input)
{
    input_stack->array[input_stack->top] = input;
    input_stack->top++;
}

int pop(stack *input_stack)
{
    input_stack->top--;
    return input_stack->array[input_stack->top];
}

void print_array(stack *input_stack)
{
    printf("My top reference: %i\n", input_stack->top);
    printf("My array is: ");
    for (int j = 0; j < input_stack->top; j++)
    {
        printf("%i ", input_stack->array[j]);
    }
    printf("\n");
}
