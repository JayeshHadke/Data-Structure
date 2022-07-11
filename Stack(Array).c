#include <stdio.h>
#include <stdlib.h>
int f = -1;
void push(int s[], int size, int value)
{
    if (f == size - 1)
    {
        printf("Stack is overflow\n");
    }
    else
    {
        if (f == -1)
        {
            f = 0;
        }
        else
        {
            f++;
        }
        s[f] = value;
    }
}
void pop(int s[], int size)
{
    if (f == -1)
    {
        printf("Stack is Underflow\n");
    }
    else
    {
        s[f] = '\0';
        if (f == 0)
        {
            f = -1;
        }
        else
        {
            f--;
        }
    }
}
void display(int s[], int size)
{
    if (f == -1)
    {
        printf("NO elements to display\n");
    }
    else
    {
        for (int i = 0; i <= f; i++)
        {
            printf(">>%d", s[i]);
        }
        printf("\n");
    }
}

void main()
{
    int size, value, option;
    printf("Enter Size of Stack\n");
    scanf("%d", &size);
    int s[size];
    while (1)
    {
        printf("Enter Option\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter Value\n");
            scanf("%d", &value);
            push(s, size, value);
            break;
        case 2:
            pop(s, size);
            break;
        case 3:
            display(s, size);
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