#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Variables
    int vowel_count = 0;
    int consonant_count = 0;
    int nonalpha_count = 0;

    // Receving the input
    string input = get_string("Input: ");

    // Looping the input to count vowels, consonants, non-alphabetic characters
    for (int len = strlen(input), i = 0; i < len; i++)
    {
        // Counting only ASCII characters, for now, ignoring UTF-8 challanges
        if (tolower(input[i]) == 97 || tolower(input[i]) == 101 || tolower(input[i]) == 105 || tolower(input[i]) == 111 || tolower(input[i]) == 117 )
        {
            vowel_count++;
        }
        else if (!isalpha(input[i]))
        {
            nonalpha_count++;
        }
        else
        {
            consonant_count++;
        }
    }

    printf("Vowels: %i\n", vowel_count);
    printf("Consonants: %i\n", consonant_count);
    printf("Non-alphabetic: %i\n", nonalpha_count);

}
