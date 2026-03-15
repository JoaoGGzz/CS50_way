#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;

    printf("n: ");
    scanf("%i", &n);

    int *a = malloc(n * sizeof(int));
    if (a == NULL)
    {
        return 1;
    }

    for (int i = 0, len = n * sizeof(int); i < len; i++)
    {
        a[i] = i * i;
    }

    for (int i = 0, len = n * sizeof(int); i < len; i++)
    {
        printf("%i, ", a[i]);
    }
    printf("\n");

    free(a);
}
