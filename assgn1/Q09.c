// WAP to reverse all array elements without using temporary variables.

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n / 2; i++)
    {
        arr[i] = arr[i] + arr[n - i - 1];
        arr[n - i - 1] = arr[i] - arr[n - i - 1];
        arr[i] = arr[i] - arr[n - i - 1];
    }

    printf("Array after reversing:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}