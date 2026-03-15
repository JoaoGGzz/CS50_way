#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Variable
    int n = 50;

    // Declaring a pointer that stores an integer's address
    int *p = &n;

    // Printing the integer address of N
    printf("%p\n", &n);

    // Printing the integer address of N
    printf("%p\n", p);

    // Printing the value of N that is pointed of *P
    printf("%i\n", *p);

    // Printing the pointer's address
    printf("%p\n", &p);

    // Leaving the "training wheels" of CS50.h, no more using string data type
    char *t = "HO!";

    // Printing the value of hole char *t
    printf("%s\n", t);

    // Printing the address of char *t
    printf("%p\n", t);

    // Printing the first value in ASCII of char *t, that is the letter 'H'
    printf("%i\n", *t);

    printf("%i\n", *(t+1));

    char *y = "HI!";
    printf("%c\n", y[0]);
    printf("%c\n", y[1]);
    printf("%c\n", y[2]);

    printf("%c\n", *y);
    printf("%c\n", *(y + 1));
    printf("%c\n", *(y + 2));

    printf("%p\n", y);
    printf("%p\n", (y + 1));
    printf("%p\n", (y + 2));

    printf("%s\n", y);
    printf("%s\n", y + 1);
    printf("%s\n", y + 2);

    // Get a string
    string k = get_string("k: ");

    // Copy string's address
    string j = k;

    // Capitalize first letter in string
    if (strlen(j) > 0)
    {
        j[0] = toupper(j[0]);
    }

    // Print string twice
    printf("k: %s\n", k);
    printf("j: %s\n", j);
}
