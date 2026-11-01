#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted\n", x);
}

void dequeue()
{
    struct Node *temp;

    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = front;
        printf("%d deleted\n", front->data);

        front = front->next;

        if (front == NULL)
            rear = NULL;

        free(temp);
    }
}

void display()
{
    struct Node *temp = front;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();

    printf("Queue elements: ");
    display();

    return 0;
}