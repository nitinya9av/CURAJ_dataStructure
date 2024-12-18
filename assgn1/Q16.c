#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1;
int n;
int *queue;

void createqueue()
{
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    
    queue = (int *)malloc(n * sizeof(int));
}

int isempty()
{
    return front == -1;
}

int isfull()
{
    return rear == n - 1;
}

void enqueue(int num)
{
    if (isfull())
    {
        printf("Queue is full\n");
        return;
    }
    if (isempty())
    {
        front = 0;
    }
    queue[++rear] = num;
}

void dequeue()
{
    if (isempty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued: %d\n", queue[front]);
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
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

void initialize_queue()
{
    int num;
    printf("Initialize the queue with elements:\n");
    while (!isfull())
    {
        printf("Enter a number: ");
        scanf("%d", &num);
        enqueue(num);
    }
    printf("Queue is now full.\n");
}

int main()
{
    createqueue();
    initialize_queue();

    int choice, num;
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number to enqueue: ");
            scanf("%d", &num);
            enqueue(num);
            break;
        case 2:
            dequeue();
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