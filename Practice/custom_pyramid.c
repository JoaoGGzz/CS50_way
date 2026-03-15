#include <stdio.h>
#include <cs50.h>

// Protype
void pyramid(int h);

int height;

int main(void)
{
    // Check for valid input
    do
    {
        height = get_int("Height: ");
        if (height < 2)
        {
            printf("Minimun height is 2\n");
        }
    }
    while (height < 2);

    // Function to construct the pyramid
    pyramid(height);

}

void pyramid(int h)
{
    int first_blocks = 0;
    int spaces = h;
    int center_spaces = 0;
    int second_blocks = 0;

    // First empty spaces to the first block
    for (int n = 0; n < h; n++)
    {
        printf(" ");
    }

    // First individual block
    printf("#");
    printf("\n");

    // Loop to iterate through the height
    for (int i = 0; i < h; i++)
    {

        // Second empty spaces to the others blocks
        spaces--;
        for (int k = 0; k < spaces; k++)
        {
            printf(" ");
        }

        // Adding the first side blocks
        other_blocks++;
        for (int j = 0; j < other_blocks; j++)
        {
            printf("#");
        }

        // The center empty space
        printf(" ");

        // Adding the other side blocks
        for (int m = 0; m < other_blocks; m++)
        {
            printf("#");
        }
        printf("\n");
    }
}
