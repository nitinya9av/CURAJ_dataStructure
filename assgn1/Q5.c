// Insert an element into an array on a given index. 


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

    int num, index;
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

    return 0;
}
