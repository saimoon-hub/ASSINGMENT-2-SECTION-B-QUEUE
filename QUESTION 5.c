#include <stdio.h>
#include <string.h>
#define MAX 100

char queue[MAX][20];
int front = 0, rear = -1;

void enqueue(char str[])
{
    rear++;
    strcpy(queue[rear], str);
}

void generateBinary(int n)
{
    char temp[20];
    int i;

    enqueue("1");

    for (i = 1; i <= n; i++)
    {
        strcpy(temp, queue[front]);

        printf("%s ", temp);

        front++;

        char a[20], b[20];

        strcpy(a, temp);
        strcpy(b, temp);

        strcat(a, "0");
        strcat(b, "1");

        enqueue(a);
        enqueue(b);
    }
}

int main()
{
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Binary numbers from 1 to %d:\n", n);

    generateBinary(n);

    return 0;
}