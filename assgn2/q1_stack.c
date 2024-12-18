// 1. Implement Stack using array with creation of two functions push(),pop() and display().
//     a) push(): whenever you insert a element into stack call this function.
//     b) pop(): whenever you delete a element from stack call this function.
//     c) display(): Display all stack elements.


#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;
int MAX;

void initStack(int size) {
    MAX = size;
    stack = ( int *)malloc(MAX * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int num) {
    if (isFull()) {
        printf("Stack is full\n");
        return;
    }
    stack[++top] = num;
}

void pop() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Popped element: %d\n", stack[top--]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    initStack(size);

    while (!isFull())
    {
        int num;
        printf("Enter the element to push: ");
        scanf("%d", &num);
        push(num);
    }

    int choice, num;
    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &num);
                push(num);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}







































/*
#include <stdio.h>
#include <stdlib.h>

#define MAX 5
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

void pop()
{
    if (isempty())
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Popped element: %d\n", stack[top--]);
}

void display()
{
    if (isempty())
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int choice, num;

    while (!isfull())
    {
        printf("Enter the element to push: ");
        scanf("%d", &num);
        push(num);
    }

    while (1)
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &num);
            push(num);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
*/