#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
// #include <math.h>

// Main
int main(void)
{
    // Declaração e recebimento da entrada
    float count_letters = 0;
    float count_spaces = 0;
    float count_words = 0;
    float count_sentences = 0;
    string user_text = get_string("Text: ");

    // Contar a primeira palavra
    // if (isalpha(user_text[0]))
    // {
    //    count_words++;
    // }

    // Cálculo do index de Coleman-Liau

    // Contagem da quantidade de letras, palavras e sentenças
    for (int i = 0, len = strlen(user_text); i < len; i++)
    {
        // Contagem de letras padrão
        if (isalpha(user_text[i]))
        {
            count_letters++;
        }
        float verificar = user_text[i-1];

        // Contagem de palavras, desconsiderando espaços múltiplos
        // if (user_text[i-1] == ' ' && isalpha(user_text[i]))
        // {
        //    count_words++;
        // }

        // Contagem de palavras, através da quantidade de espaços
        if (user_text[i] == ' ')
        {
            count_spaces++;
        }

        // Contagem de sentenças
        if (user_text[i] == '.' || user_text[i] == '!' || user_text[i] == '?')
        {
            count_sentences++;
        }
    }

    // Contagem de palavras, através da quantidade de espaços
    count_words = count_spaces + 1;

    // Cálculo de média de letras por palavras
    float avg_letters = (count_letters / count_words);

    // Cálculo da média de letras por 100 palavras
    float L = avg_letters * 100;

    // Cálculo da média de sentenças por palavras
    float avg_sentences = (count_sentences / count_words);

    // Cálculo da média de sentenças por 100 palavras
    float S = avg_sentences * 100;

    // Parte final do cálculo
    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    // Mostrar resultado
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index < 16)
    {
        // printf("Grade %f \n", index);
        printf("Grade %.0f\n", index);
        // printf("Grade %f \n", round(index));
    }
    else
    {
        printf("Grade 16+\n");
    }
}
