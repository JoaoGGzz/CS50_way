#include <cs50.h>
#include <stdio.h>

int array_100[101];

int main(void)
{
    for (int i = 0; i <= 100; i++)
    {
        array_100[i] = i;
        printf("%i\n",array_100[i]);
    }
    printf("%i\n", array_100[0]);
    printf("%i\n", array_100[10]);
    printf("%i\n", array_100[99]);
    printf("%i\n", array_100[100]);
}

