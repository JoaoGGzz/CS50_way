#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Stores and prints an integer via its address
    int n = 50;
    int *p = &n;
    printf("n value is:    %i\n", n);
    printf("n address is:  %p\n", &n);
    printf("*p value is:   %i\n", *p);
    printf("*p address is: %p\n", &p);
    printf("*p address is: %p\n", p);

    // Prints a string's address as well the addresses of its chars
    string s = "HI!";
    printf("%p\n", s);
    printf("%p\n", &s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

    // Declares a string without CS50 Library
    char *string = "HO!";
    printf("%s\n", string);

    // Prints a string's chars
    char *st = "HU!";
    printf("%c\n", st[0]);
    printf("%c\n", st[1]);
    printf("%c\n", st[2]);

   // Prints a string's chars via pointer arithmetic
    printf("%c\n", *st);
    printf("%c\n", *(st + 1));
    printf("%c\n", *(st + 2));

    // Prints substrings via pointer arithmetic
    printf("%s\n", st);
    printf("%s\n", st + 1);
    printf("%s\n", st + 2);

}

