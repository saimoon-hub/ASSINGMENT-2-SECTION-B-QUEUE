#include <stdio.h>
#define MAX 5

int queue[MAX];
int stack[MAX];

int front = 0, rear = -1;
int top = -1;

void enqueue(int x)
{
    if (rear == MAX - 1)
        printf("Queue is full\n");
    else
        queue[++rear] = x;
}

void reverse()
{
    int i;

    while (front <= rear)
    {
        stack[++top] = queue[front];
        front++;
    }

    front = 0;
    rear = -1;

    while (top != -1)
    {
        queue[++rear] = stack[top--];
    }
}

void display()
{
    int i;

    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("Original Queue: ");
    display();

    reverse();

    printf("\nReversed Queue: ");
    display();

    return 0;
}