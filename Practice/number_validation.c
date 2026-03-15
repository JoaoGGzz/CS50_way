#include <stdio.h>
#include <cs50.h>

int number;

int main(void)
{
    // Check for the ideal condition
    do
    {
        number = get_int("Insert a positive number: ");

        // 
        if (number <= 0)
        {
            printf("\nPlease, just positive numbers are available\n\n");
        }
    }
    while (number <= 0);

    printf("\nDone!\n");
}

