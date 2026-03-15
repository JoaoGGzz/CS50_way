#include <cs50.h>
#include <stdio.h>

// Quando apliquyei o design50, foi me recomendando utilizar loops para lidar com esses ifs aninhados, porém, nesse momento, não enxergo como fazer isso na pratica.
// Também me foi sugerido utilizar uma variavel genéria para os restos das divisões "rest_25, rest_10", em "rest_remaining", porém na logica que utilizei fez muito sentido enxergar qual resto era de cada operação

int main(void)
{
    int change_owed;

    do
    {
        change_owed = get_int("Change owed: ");
    }
    while (change_owed < 0);

    int coin_25;
    int coin_10;
    int coin_5;
    int coin_1;
    int rest_25;
    int rest_10;
    int rest_5;
    int rest_1;
    int total_coins = 0;

    if (change_owed >= 25)
    {
        coin_25 = change_owed / 25;
        rest_25 = change_owed % 25;
        total_coins = total_coins + coin_25;

        if (rest_25 >= 10)
        {
            coin_10 = rest_25 / 10;
            rest_10 = rest_25 % 10;
            total_coins = total_coins + coin_10;

            if (rest_10 >= 5)
            {
                coin_5 = rest_10 / 5;
                rest_5 = rest_10 % 5;
                total_coins = total_coins + coin_5;

                if (rest_5 >= 1)
                {
                    coin_1 = rest_5 / 1;
                    rest_1 = rest_5 % 1;
                    total_coins = total_coins + coin_1;
                    printf("%i \n", total_coins);
                }

                else if (rest_5 == 0)
                {
                    printf("%i \n", total_coins);
                }
            }

            else if (rest_10 >= 1)
            {
                coin_1 = rest_10 / 1;
                rest_1 = rest_10 % 1;
                total_coins = total_coins + coin_1;
                printf("%i \n", total_coins);
            }

            else if (rest_10 == 0)
            {
                printf("%i \n", total_coins);
            }
        }

        else if (rest_25 >= 5)
        {
            coin_5 = rest_25 / 5;
            rest_5 = rest_25 % 5;
            total_coins = total_coins + coin_5;

            if (rest_5 >= 1)
            {
                coin_1 = rest_5 / 1;
                rest_1 = rest_5 % 1;
                total_coins = total_coins + coin_1;
                printf("%i \n", total_coins);
            }

            else if (rest_5 == 0)
            {
                printf("%i \n", total_coins);
            }
        }

        else if (rest_25 >= 1)
        {
            coin_1 = rest_25 / 1;
            rest_1 = rest_25 % 1;
            total_coins = total_coins + coin_1;
            printf("%i \n", total_coins);
        }

        else if (rest_25 == 0)
        {
            printf("%i \n", total_coins);
        }
    }

    else if (change_owed >= 10)
    {
        coin_10 = change_owed / 10;
        rest_10 = change_owed % 10;
        total_coins = total_coins + coin_10;

        if (rest_10 >= 5)
        {
            coin_5 = rest_10 / 5;
            rest_5 = rest_10 % 5;
            total_coins = total_coins + coin_5;

            if (rest_5 >= 1)
            {
                coin_1 = rest_5 / 1;
                rest_1 = rest_5 % 1;
                total_coins = total_coins + coin_1;
                printf("%i \n", total_coins);
            }
            else if (rest_5 == 0)
            {
                printf("%i \n", total_coins);
            }
        }

        else if (rest_10 >= 1)
        {
            coin_1 = rest_10 / 1;
            rest_1 = rest_10 % 1;
            total_coins = total_coins + coin_1;
            printf("%i \n", total_coins);
        }

        else if (rest_10 == 0)
        {
            printf("%i \n", total_coins);
        }
    }

    else if (change_owed >= 5)
    {
        coin_5 = change_owed / 5;
        rest_5 = change_owed % 5;
        total_coins = total_coins + coin_5;

        if (rest_5 >= 1)
        {
            coin_1 = rest_5 / 1;
            rest_1 = rest_5 % 1;
            total_coins = total_coins + coin_1;
            printf("%i \n", total_coins);
        }

        else if (rest_5 == 0)
        {
            printf("%i \n", total_coins);
        }
    }

    else if (change_owed >= 1)
    {
        coin_1 = change_owed / 1;
        rest_1 = change_owed % 1;
        total_coins = total_coins + coin_1;
        printf("%i \n", total_coins);
    }

    else if (change_owed == 0)
    {
        total_coins = change_owed;
        printf("%i \n", total_coins);
    }
}
