#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("%i\n", '\0');
    printf("%i\n", "0"[0]);
    printf("%i\n", "\0"[0]);
    // Exercício 1 - Apenas Peça ao usuário um número inteiro positivo. Se ele digitar 0 ou negativo, peça novamente até ser válido.
    //int n;
    //do
    //{
    //    n = get_int("Please, enter a positivo integer number: ");
    //}
    //while (n <= 0);

    //printf("O número digitado foi: %i\n", n);

    // Exerício 2 - O programa deve continuar exibindo o menu até o usuário escolher sair.
    //int n;
    //do
    //{
    //    printf("1 - Cadastrar\n2 - Listar\n3 - Sair\n");
    //    n = get_int("");
    //}
    //while (n != 3);

    // Exerício 3 - Peça um número entre 1 e 10. Enquanto o valor estiver fora desse intervalo, continue pedindo.
    //int n;
    //do
    //{
    //    n = get_int("Por favor, insira um número entre 1 e 10\n");
    //}
    //while(n < 1 || n > 10);

    // Defina uma senha fixa no código (ex: 1234). Peça ao usuário até ele acertar.
    //int senha;
    //do
    //{
    //    senha = get_int("Insira a senha: ");
    //}
    //while(senha != 1234);

    //printf("Acertou, miseravi! ");


    // Exercício 5 — Comparação direta com while. Pegue qualquer exercício acima e faça duas versões: Usando do while e outra versão usando só while
    //while (true)
    //{
    //    int senha = get_int("Por favor, insira a senha: ");
    //    if (senha != 1234)
    //    {
    //        continue;
    //    }
    //    else
    //    {
    //        printf("Acertô, miserávi!\n");
    //        break;
    //    }
    //}

    // Alterando a lógica do while para ter um código mais enxuto
    //while (true)
    //{
    //    int senha = get_int("Por favor, insira a senha: ");
    //    if (senha == 1234)
    //    {
    //        printf("Acertô, miserávi!\n");
    //        break;
    //    }
    //}

}
