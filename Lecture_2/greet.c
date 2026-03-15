// Prints a command-line argument

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    printf("%i\n", argc);
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
        printf("%s\n", argv[0]);
        printf("%s\n", argv[2]);
        printf("%i \n" , (atoi(argv[1]) % 26));
    }
    else
    {
        printf("hello, world\n");
    }
}
