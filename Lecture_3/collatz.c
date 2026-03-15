#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int count = 0;

int main(void)
{
    int n = get_int("Insert: ");
    collatz(n);
    printf("A quantidade de passos necessários foi: %i\n", count);
}

int collatz(int n)
{
    if (n == 1)
    {
        return 1;
    }

    else if ((n % 2) == 0)
    {
        collatz(n / 2);
        count++;
        return printf("%i\n", n);
    }
    else
    {
        collatz((n * 3) + 1);
        count++;
        return printf("%i\n", n);
    }

}

// RESOLUÇÃO DO PROFESSOR (SOMENTE PARA A FUNÇÃO COLLATZ)
// int collatz(int n)
// {
//      Caso base
//      if (n == 1)
//          return 0;
//      else if ((n % 2) == 0)
//          return 1 + collatz(n/2);
//      else
//          return 1 + collatz(3*n + 1);
// }
