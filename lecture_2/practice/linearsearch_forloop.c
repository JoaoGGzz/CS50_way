#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Declaring variables
int numbers[] = {30, 50, 10, 70, 20, 60, 90, 40, 80, 100};

int main(void)
{
    // Taking input form user to search for
    int number = get_int("Search for: ");

    // Linear search using for loop
    for (int i = 0; i < 10; i++)
    {
        if (numbers[i] == number)
        {
            printf("Found!\n");
            return 0;
        }
    }
    printf("Not found!\n");
    return 1;
}


