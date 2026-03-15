#include <stdio.h>

void set_to_zero(int *p);

int main (void)
{
    int x = 7;

    printf("O valor de x antes é: %i\n", x);

    set_to_zero(&x);

    printf("O valor de x depois é: %i\n", x);
}

void set_to_zero(int *p)
{
    int zero = 0;
    *p = zero;
}
