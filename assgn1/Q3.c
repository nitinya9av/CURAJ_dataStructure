// Write a program to enter a no. and find the location of that no. in an array.

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

    int num;
    printf("Enter the number to find: ");
    scanf("%d", &num);

    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            printf("Number found at location %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Number not found\n");
    }

    // Insert an element into an array on a given index. 

    int num2, index;
    printf("Enter the number to insert: ");
    scanf("%d", &num);
    printf("Enter the index to insert: ");
    scanf("%d", &index);

    if (index < 0 || index > n)
    {
        printf("Invalid index\n");
    }
    else
    {
        for (int i = n - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = num;
        n++;

        printf("Array after insertion:\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    // Delete an element from the array by value.

    int value;
    printf("Enter the value to delete: ");
    scanf("%d", &value);

    int found1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            found1 = 1;
            for (int j = i; j < n - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            n--;
            i--;
        }
    }

    if (!found1)
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