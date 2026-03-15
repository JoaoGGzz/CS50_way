#include <stdio.h>

int main(void)
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;

    printf("%lu %lu\n", sizeof(arr), sizeof(p));

    printf("arr:        %p\n", arr);
    printf("arr[0]:     %p\n", &arr[0]);
    printf("arr[1]:     %p\n", &arr[1]);
    printf("arr + 1:    %p\n", arr + 1);
    printf("*(arr + 1): %i\n", *(arr + 1));
    printf("arr[1]:     %i\n", arr[1]);
}
