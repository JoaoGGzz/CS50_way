#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string nome;
    int idade;
    float altura;
} Person;

Person pessoa[2];

int main(void)
{

pessoa[0].nome = "João";
pessoa[0].idade = 33;
pessoa[0].altura = 1.91;

pessoa[1].nome = "Aline";
pessoa[1].idade = 27;
pessoa[1].altura = 1.70;

printf("%s\n", pessoa[0].nome);
printf("%i\n", pessoa[0].idade);
printf("%.2f\n", pessoa[0].altura);

printf("%s\n", pessoa[1].nome);
printf("%i\n", pessoa[1].idade);
printf("%.2f\n", pessoa[1].altura);

}
