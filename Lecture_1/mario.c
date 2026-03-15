// Library
#include <stdio.h>

// Prototype
void print_row(int width);

// Main function (Trigger button on Scratch)
int main(void)
{
    // Constant variable and for loop
    const int n = 5;
    for (int i = 0; i < n; i++)
    {
        print_row(n);
    }
}

// Own function for printing rows base in some input
void print_row(int width)
{
    for (int i = 0; i < width; i++)
    {
        printf("#");
    }
    printf("\n");
}


