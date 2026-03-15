// Libraries
#include <cs50.h>
#include <stdio.h>

// Prototypes
void print_space(int width);
void print_hash(int input);
void print_two_spaces(void);

int main(void)
{
    // Declaring variables
    int count = 0;

    // Getting the height number
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    int auxiliar_variable = height;

    // Print the hashs + empty spaces
    for (int t = 0; t < height; t++)
    {
        print_space(auxiliar_variable);
        auxiliar_variable--;
        count++;
        print_hash(count);
        print_two_spaces();
        print_hash(count);
        printf("\n");
    }
}

void print_space(int width)
{
    for (int i = 0; i < width - 1; i++)
    {
        printf(" ");
    }
}

void print_hash(int width)
{
    for (int j = 0; j < width; j++)
    {
        printf("#");
    }
}

void print_two_spaces(void)
{
    printf("  ");
}
