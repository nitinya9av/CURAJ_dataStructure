// Delete an element from the array by value.

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

    int value;
    printf("Enter the value to delete: ");
    scanf("%d", &value);

    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            found = 1;
            for (int j = i; j < n - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            n--;
            i--;
        }
    }

    if (!found)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Array after deletion:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}