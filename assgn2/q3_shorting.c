// Enter n numbers and sort them by using Quick Sort through STACK.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

int isfull()
{
    return top == MAX - 1;
}

int isempty()
{
    return top == -1;
}

void push(int data)
{
    if (isfull())
    {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = data;
}

int pop()
{
    if (isempty())
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top--];
}

int peek()
{
    if (isempty())
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    push(low);
    push(high);
    while (!isempty())
    {
        high = pop();
        low = pop();
        if (low < high)
        {
            int pi = partition(arr, low, high);
            push(low);
            push(pi - 1);
            push(pi + 1);
            push(high);
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}