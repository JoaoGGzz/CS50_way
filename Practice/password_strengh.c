#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // Variable to store the conditions status
    bool check_password[4] = {false, false, false};

    printf("\n=====> Simple Password Checker <=====\n");

    // Receiving the password
    string password = get_string("Password: ");

    // Looping the password to check conditions
    for (int i = 0, len = strlen(password); i < len; i++)
    {
        // Checking if there's a CAPITAL letter
        if (password[i] >= 65 && password[i] <= 90)
        {
            check_password[0] = true;
        }

        // Checking if there's a number
        else if (password[i] >= 48 && password[i] <= 57)
        {
            check_password[1] = true;
        }

        // Checking if there's minimun 8 characters lengh
        else if (len >= 8)
        {
            check_password[2] = true;
        }
    }

    // Validating if the password is strong or not
    if (check_password[0] == true && check_password[1] == true && check_password[2] == true)
    {
        printf("Strong password\n");
    }
    else
    {
        printf("Invalid password\n");
    }
}
