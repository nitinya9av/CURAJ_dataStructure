// Implement Stack and Queue operations using link list.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;
struct Node *front = NULL;
struct Node *rear = NULL;

void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf(" %d ", n->data);
        n = n->next;
    }
}

void push(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = top;
    top = new_node;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Popped element: %d\n", top->data);
    top = top->next;
}

void enqueue(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = new_node;
        return;
    }
    rear->next = new_node;
    rear = new_node;
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued element: %d\n", front->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
}

int main()
{
    int choice, data;
    struct Node *temp;

    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Enqueue\n4. Dequeue\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 4:
            dequeue();
            break;
        case 5:
            printf("Stack: ");
            printList(top);
            printf("\nQueue: ");
            printList(front);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}