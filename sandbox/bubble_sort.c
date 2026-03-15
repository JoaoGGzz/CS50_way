#include <stdio.h>

int main(void)
{
    // Variables to allow the manipulating proccess
    int unsorted_array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int aux_1;
    int aux_2;
    int lengh = 10;

    // Looping on all chances inside the given array
    for (int i = 0; i < lengh; i++)
    {
        // Printing every iteration
        for (int k = 0; k < lengh; k++)
        {
            printf("%i ", unsorted_array[k]);
        }
        printf("\n");

        // Making the bubble sort
        for (int j = 0; j < lengh; j++)
        {
            // Checking if the next number is smaller than the previous number
            if (unsorted_array[j] > unsorted_array[j+1])
            {
                // Storing the values to allow the swap
                aux_1 = unsorted_array[j];
                aux_2 = unsorted_array[j+1];

                // Swaping them
                unsorted_array[j] = aux_2;
                unsorted_array[j+1] = aux_1;

            }
        }
    }

}
