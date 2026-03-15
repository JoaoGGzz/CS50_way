#include <stdio.h>

int array_sum(int *a, int n);

int main(void)
{
    int s;
    int arr[5] = {10, 20, 30, 40, 50};

    s = array_sum(arr, sizeof(arr)/4);

    printf("%i\n", s);

    printf("%i\n", arr[0]);
}

int array_sum(int *a, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        //sum += *(a + i);
    }

    a[0] = 999;

    return sum;
}
