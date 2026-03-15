#include <stdio.h>
#include <cs50.h>

// Starting the code
int main(void)
{
    // Receive input
    string name = get_string("Please, what's your name: ");

    // Printing the name
    printf("hello, %s\n", name);
}
