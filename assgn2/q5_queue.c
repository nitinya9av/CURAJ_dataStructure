// Write Code to perform operations on simple queue.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isfull()
{
    return rear == MAX - 1;
}

int isempty()
{
    return front == -1 || front > rear;
}

void enqueue(int data)
{
    if (isfull())
    {
        printf("Queue is full\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    queue[++rear] = data;
}

int dequeue()
{
    if (isempty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue[front];
    front++;
    if (front > rear)
    {
        front = rear = -1;
    }
    return data;
}

int peek()
{
    if (isempty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    return queue[front];
}

void display()
{
    if (isempty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            int data;
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            printf("Dequeued element: %d\n", dequeue());
            break;
        case 3:
            printf("Front element: %d\n", peek());
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}