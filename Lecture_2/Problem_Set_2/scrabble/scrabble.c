#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Prototipo função
int checa_valores(string entrada);

// Função principal
int main(void)
{
    // Receber entrada do usuário
    string primeira = get_string("Player 1: ");
    string segunda = get_string("Player 2: ");

    // Realizar checagem de qual nome inserido possui maior quantidade de pontos
    int p1 = checa_valores(primeira);
    int p2 = checa_valores(segunda);

    // Informar se foi vitória, derrota ou empate
    if (p1 > p2)
    {
        printf("Player 1 wins! \n");
    }

    else if (p1 < p2)
    {
        printf("Player 2 wins! \n");
    }

    else
    {
        printf("Tie! \n");
    }
}

// Função para determinar os valores das entradas, retornando o somatório dos valores de cada letra
int checa_valores(string entrada)
{
    int tamanho = strlen(entrada);
    int acumuladora = 0;

    for (int i = 0; i < tamanho; i++)
    {
        char letra = toupper(entrada[i]);
        if (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'L' || letra == 'N' || letra == 'O' || letra == 'R' || letra == 'S' || letra == 'T' || letra == 'U')        {
            acumuladora++;
        }

        else if (letra == 'D' || letra == 'G')
        {
            acumuladora += 2;
        }

        else if (letra == 'B' || letra == 'C' || letra == 'M' || letra == 'P')
        {
            acumuladora += 3;
        }

        else if (letra == 'F' || letra == 'H' || letra == 'V' || letra == 'W' || letra == 'Y')
        {
            acumuladora += 4;
        }

        else if (letra == 'K')
        {
            acumuladora += 5;
        }

        else if (letra == 'J' || letra == 'X')
        {
            acumuladora += 8;
        }

        else if (letra == 'Q' || letra == 'Z')
        {
            acumuladora += 10;
        }
    }

    return acumuladora;
}
