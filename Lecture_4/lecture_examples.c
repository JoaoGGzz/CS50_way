// Capitalizes a copy of a string, defining n in loop too

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Demonstrates memory errors via valgrind

    int *x = malloc(3 * sizeof(int));
    x[0] = 72;
    x[1] = 73;
    x[3] = 33;
    free(x);
}
