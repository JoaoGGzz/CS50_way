#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("=====> Average calculator <=====\n");

    // Check for valid input and making the calculus easier
    int size;
    do
    {
        size = get_int("How many numbers? ");
        if (size < 1)
        {
            printf("Please, just plus 1 numbers\n");
        }
    }
    while (size < 1);

    // Average calculus
    int accumulator = 0;
    for (int i = 0; i < size; i++)
    {
        accumulator += get_int("Number %i: \n", i + 1);
    }

    printf("Average is: %d\n", accumulator / size);

}
