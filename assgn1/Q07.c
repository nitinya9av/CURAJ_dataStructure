// Perform binary search on array elements.

#include <stdio.h>

int binarySearch(int arr[], int n, int num)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == num)
        {
            return mid;
        }
        else if (arr[mid] < num)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array in sorted order:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int num;
    printf("Enter the number to find: ");
    scanf("%d", &num);

    int index = binarySearch(arr, n, num);
    if (index != -1)
    {
        printf("Number found at location %d\n", index + 1);
    }
    else
    {
        printf("Number not found\n");
    }

    return 0;
}