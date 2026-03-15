#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes
int LuhnAlgo(char input[]);

int main(void)
{
    long cardNumber;

    // Receiving the valid card number
    do
    {
        cardNumber = get_long("Number: ");
    }
    while (cardNumber < 0);

    // Converting the long into string (To allow me manipulate it)
    char str[17];
    sprintf(str, "%li", cardNumber);

    // Defining if is AMEX, MASTERCARD, VISA or INVALID
    // VISA Case
    if (str[0] == '4' && (strlen(str) == 13 || strlen(str) == 16))
    {
        if (LuhnAlgo(str) % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    // AMEX Case
    else if (((str[0] == '3' && str[1] == '4') || (str[0] == '3' && str[1] == '7')) &&
             (strlen(str) == 15))
    {
        if (LuhnAlgo(str) % 10 == 0)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    // MASTERCARD Case
    else if (((str[0] == '5' && str[1] == '1') || (str[0] == '5' && str[1] == '2') ||
              (str[0] == '5' && str[1] == '3') || (str[0] == '5' && str[1] == '4') ||
              (str[0] == '5' && str[1] == '5')) &&
             (strlen(str) == 16))
    {
        if (LuhnAlgo(str) % 10 == 0)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    // INVALID Case
    else
    {
        printf("INVALID\n");
    }
}

int LuhnAlgo(char input[])
{
    // Counting how many characters do we have
    int elements = strlen(input);
    int sum = 0;
    char aux[20];
    int aux_index = 0;

    // First - Multiply by 2 starting the number's second-to-last digit and sum all digits
    for (int i = elements - 2; i >= 0; i -= 2)
    {
        // Converting the ASCII code to real number and multiply by 2
        int m_2 = (input[i] - '0') * 2;

        // Taking each digit for numbers with two digits (bigger equal then 10) and sum them all
        if (m_2 >= 10)
        {
            m_2 = (m_2 / 10) + (m_2 % 10);
        }
        // Sum the digits
        sum += m_2;
    }

    // Second - Sum the other digits weren't multiplied by 2
    for (int i = elements - 1; i >= 0; i -= 2)
    {
        int od = input[i] - '0';
        sum += od;
    }

    return sum;
}
