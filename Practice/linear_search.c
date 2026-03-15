#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Declaring an array to search for some number
    int array[] = {1, 10, 25, 34, 47, 56, 61, 72, 88, 93};

    // Receiving the input number to search
    int input = get_int("Input: ");

    // Linear seach on given array
    for (int i = 0; i < 10; i++)
    {
        if (input == array[i])
        {
            printf("Number %i found!\n", input);
            return 0;
        }
    }

    printf("Number %i not found!\n", input);
}
