#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string nome;
    int nota;
} Student;

int main(void)
{
    Student students[3];

    students[0].nome = "Sany";
    students[0].nota = 5;

    students[1].nome = "Tinky";
    students[1].nota = 7;

    students[2].nome = "Winky";
    students[2].nota = 3;

    for(int i = 0; i < 3; i++)
    {
        printf("Nome do estudante: %s\n", students[i].nome);
        printf("Nota do estudante: %i\n", students[i].nota);
    }
}
