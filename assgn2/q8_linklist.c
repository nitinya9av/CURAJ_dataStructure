/*
2. insert a node in link list
    a) Before first node.
    b) After given node
    c) End of the List
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void displayList(struct Node *n)
{
    while (n != NULL)
    {
        printf(" %d ", n->data);
        n = n->next;
    }
}

void insertAtFirst(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAfter(struct Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insertAtEnd(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

int main()
{
    struct Node *head = NULL;
    int choice, data, position;
    struct Node *temp;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert after a given node\n");
        printf("3. Insert at the end\n");
        printf("4. Display the linked-list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to insert at the beginning: ");
            scanf("%d", &data);
            insertAtFirst(&head, data);
            break;
        case 2:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            printf("Enter the position after which to insert (0-based index): ");
            scanf("%d", &position);
            temp = head;
            for (int i = 0; i < position; i++)
            {
                if (temp == NULL)
                {
                    printf("Position out of bounds\n");
                    break;
                }
                temp = temp->next;
            }
            if (temp != NULL)
            {
                insertAfter(temp, data);
            }
            break;
        case 3:
            printf("Enter the data to insert at the end: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 4:
            printf("Linked list: ");
            displayList(head);
            printf("\n");
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}