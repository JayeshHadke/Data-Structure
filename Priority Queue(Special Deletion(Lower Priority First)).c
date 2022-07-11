#include <stdio.h>
#include <stdlib.h>
int f = -1, r = -1;
void enqueue(int q[], int size, int value)
{
    if (r == size - 1)
    {
        printf("Queue is Full\\Queue is overflow\n");
    }
    else
    {
        if (f == -1 && r == -1)
        {
            f = 0, r = 0;
        }
        else
        {
            r++;
        }
        q[r] = value;
    }
}
void dequeue(int q[], int size)
{
    if (f == -1 && r == -1)
    {
        printf("Queue is Underflow\n");
    }
    else
    {
        int val = q[f], count = f;
        for (int i = f; i <= r; i++)
        {
            if (val > q[i])
            {
                val = q[i];
                count = i;
            }
        }
        for (int i = count; i > f; i--)
        {
            q[i] = q[i - 1];
        }
        if (f == r)
        {
            f = -1, r = -1;
        }
        else
        {
            q[f++] = '\0';
        }
    }
}
void display(int q[], int size)
{
    if (f == -1 && r == -1)
    {
        printf("No elements in queue\n");
    }
    else
    {
        for (int i = f; i <= r; i++)
        {
            printf(">>%d", q[i]);
        }
        printf("\n");
    }
}
void main()
{
    int size, option, value;
    printf("Enter Size of Queue\n");
    scanf("%d", &size);
    int q[size];
    while (1)
    {
        printf("Enter Option\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter Value\n");
            scanf("%d", &value);
            enqueue(q, size, value);
            break;
        case 2:
            dequeue(q, size);
            break;
        case 3:
            display(q, size);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invlaid Input");
            break;
        }
    }
}