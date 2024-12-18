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

    return 0;
}