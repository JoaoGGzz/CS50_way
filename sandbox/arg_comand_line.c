#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Ensuring minimum 2 inputs
    if (argc < 3)
    {
        printf("./arg_comand_line [number1] [number2] ...\n");
        return 0;
    }

    // Variable to sum inputed numbers
    int average = 0;

    // Looping the argv to sum
    for (int i = 0; i < argc; i++)
    {
        average += atoi(argv[i]);
    }

    // Printing the result
    printf("Average is: %.2f\n", (float)average / (argc - 1));
}
