#include <stdio.h>

void correct_swap(int *a, int *b);

int main(void)
{
    int a = 1;
    int b = 2;

    printf("a: %i, b: %i\n", a, b);
    correct_swap(&a, &b);
    printf("a: %i, b: %i\n", a, b);

    return 0;
}

void correct_swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// WRONG VERSION TO UNDERSTAND DEEPER
// void correct_swap(int a, int b);

// int main(void)
// {
//     int a = 1;
//     int b = 2;

//     printf("a: %i, b: %i\n", a, b);
//     correct_swap(a, b);
//     printf("a: %i, b: %i\n", a, b);

//     return 0;
// }

// void correct_swap(int a, int b)
// {
//     int tmp = a;
//     a = b;
//     b = tmp;
// }
