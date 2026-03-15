#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Declaring variables
int numbers[] = {30, 50, 10, 70, 20, 60, 90, 40, 80, 100};
int count = 0;

int main(void)
{
    // Taking input form user to search for
    int number = get_int("Search for: ");

    // Linear search using while loop
    while (count < 10)
    {
        if (numbers[count] == number)
        {
            printf("Found!\n");
            return 0;
        }
        count++;
    }
    printf("Not found!\n");
    return 1;
}
