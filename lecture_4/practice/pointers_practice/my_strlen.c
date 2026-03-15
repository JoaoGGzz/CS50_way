#include <stdio.h>

//Prototype
int my_strlen(char *s);

int main(void)
{
    //Declaring the char * AKA string variable to use on my_strlen
    char *s1 = "Oi cara!";

    //Calling function and printing
    printf("s1 len: %i\n", my_strlen(s1));

}

//Function to count characters
int my_strlen(char *s)
{
    //Declaring a variable to count
    int count = 0;

    //Loop onto the char * variable
    while (s[count] != '\0')
    {
        count++;
    }

    return count;
}
