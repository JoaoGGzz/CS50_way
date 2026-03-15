#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int sorted_array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 11;
    int low = 0;
    int high = size - 1;

    int input = get_int("Input: ");

    while (low <= high)
    {
        int middle = low + (high - low) / 2;

        if (input == sorted_array[middle])
        {
            printf("Found at index %i\n", middle);
            return 0;
        }

        // Search left
        else if (sorted_array[middle] > input)
        {
            high = middle - 1;
        }

        // Search right
        else if (sorted_array[middle] < input)
        {
            low = middle + 1;
        }
    }

        // Not found condition
        printf("Input doesn't exist\n");
}
