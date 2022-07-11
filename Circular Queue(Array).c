#include <stdio.h>
#include <stdlib.h>
int f = -1, r = -1;
void enqueue(int sq[], int size, int value)
{
    if (f == 0 && r == size - 1)
    {
        printf("Queue Overflows\n");
    }
    else
    {
        if (f == -1 && r == -1)
        {
            f = 0, r = 0;
        }
        else
        {
            r = (r + 1) % size;
        }
        sq[r] = value;
    }
}
void dequeue(int sq[], int size)
{
    if (f == -1 && r == -1)
    {
        printf("Queue Underflows\n");
    }
    else
    {
        sq[f] = '\0';
        if (f == r)
        {
            f = -1, r = -1;
        }
        else
        {
            f = (f + 1) % size;
        }
    }
}
void display(int sq[], int size)
{
    if (f == -1 && r == -1)
    {
        printf("Queue Underflows\n");
    }
    else
    {
        int i;
        for (i = f; i != r; i = ((i + 1) % size))
        {
            printf(">>%d", sq[i]);
        }
        printf(">>%d", sq[i]);
        printf("\n");
    }
}
void main()
{
    int value, option, size;
    printf("Enter Size of Queue\n");
    scanf("%d", &size);
    int sq[size];
    while (1)
    {
        printf("Enter Option\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter Value\n");
            scanf("%d", &value);
            enqueue(sq, size, value);
            break;
        case 2:
            dequeue(sq, size);
            break;
        case 3:
            display(sq, size);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Input\n");
            break;
        }
    }
}