#include <stdio.h>

// Prototype
int max(int *a, int n);

int main(void)
{
    // Array to use
    int arr[8] = {1, 2, 3, 4, 5, 10, 9, 8};

    // Calling max function, using sizeof function to measure the array lenght
    // Using the total lenght divided by an individual element
    max(arr, sizeof(arr)/sizeof(*(arr + 0)));
}

int max(int *a, int n)
{
    // Using an aux variable to store the bigger number found
    int bigger = *(a + 0);

    // Linear search
    for (int i = 1; i < n; i++)
    {
        // Check the current number, store if it's bigger
        if (*(a + i) > bigger)
        {
            bigger = *(a + i);
        }
    }
    printf("Bigger: %i\n", bigger);
    return 0;
}
