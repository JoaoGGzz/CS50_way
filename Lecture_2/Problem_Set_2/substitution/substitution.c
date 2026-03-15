// Libraries
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>


int main(int argc, string argv[])
{
    // Verify if the user runs the script with a single comand line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key. \n");
        return 1;
    }

    // Verify if the key is valid (26 characters, only characters, each letter exactly once)
    // 26 characters check
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters. \n");
        return 1;
    }

    // Only characters check
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key must only contain alphabetic characters. \n");
            return 1;
        }
    }

    // Each letter once check
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        for (int n = i + 1, leng = strlen(argv[1]); n < leng; n++)
        {
            if (tolower(argv[1][i]) == tolower(argv[1][n]))
            {
                printf("Key must not contain repeated characters. \n");
                return 1;
            }
        }
    }

    // Prompt the user for provide the plaintext
    string plaintext = get_string("plaintext:  ");

    // Preparing the output
    printf("ciphertext: ");

    // Ciphertext (Preserving the case, non-alphabetical character not change)
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                int ref_upper = plaintext[i] - 'A';
                printf("%c", toupper(argv[1][ref_upper]));
            }

            else
            {
                int ref_lower = plaintext[i] - 'a';
                printf("%c", tolower(argv[1][ref_lower]));
            }
        }

        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
    
    return 0;

}
