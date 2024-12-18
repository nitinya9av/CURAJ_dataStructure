// WRITE A PROGRAM to append one array element of integers to another.

#include <stdio.h>

int main()
{
    int n1;
    printf("Enter the size of the first array: ");
    scanf("%d", &n1);

    int arr1[n1];
    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < n1; i++)

    {
        scanf("%d", &arr1[i]);
    }

    int n2;
    printf("Enter the size of the second array: ");
    scanf("%d", &n2);

    int arr2[n1 + n2];
    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    for (int i = 0; i < n1; i++)
    {
        arr2[n2 + i] = arr1[i];
    }

    printf("Array after appending:\n");
    for (int i = 0; i < n1 + n2; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}