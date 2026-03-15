#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct _stack
{
    int value;
    struct _stack *next;
} stack;

void print_list(stack *list);
void push_list(stack **list, int input);
void pop_list(stack **list);

int main (void)
{
    stack *list = NULL;

    for (int i = 0; i < 5; i++)
    {
        stack *n = malloc(sizeof(stack));
        if (n == NULL)
        {
            printf("Can't malloc\n");
            return 1;
        }

        n->value = get_int("Value: ");
        n->next = NULL;

        if (list == NULL)
        {
            list = n;
        }

        else
        {
            n->next = list;
            list = n;
        }
    }

    print_list(list);

    int user_input = get_int("\nPush value: ");

    push_list(&list, user_input);

    print_list(list);

    pop_list(&list);

    print_list(list);
    
    pop_list(&list);

    print_list(list);

}

void print_list(stack *list)
{
    printf("Stack is: ");
    while(list != NULL)
    {
        printf("%i ", list->value);
        list = list->next;
    }
    printf("\n");
}

void push_list(stack **list, int input)
{
    stack *m = malloc(sizeof(stack));
    if (m == NULL)
    {
        printf("Can't malloc\n");
    }

    m->value = input;
    m->next = *list;
    *list = m;
}

void pop_list(stack **list)
{
    stack *tmp = *list;
    *list = (*list)->next;
    free(tmp);
}
