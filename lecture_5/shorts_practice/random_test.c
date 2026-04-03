#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(void)
{
    // Seed random number generator
    printf("%i\n", rand());
    printf("%i\n", rand());
    printf("%i\n", rand());

    srand(5);
    printf("%i\n", rand());
    printf("%i\n", rand());
    printf("%i\n", rand());
}
