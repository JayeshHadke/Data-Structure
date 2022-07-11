#include <stdio.h>
#include <stdlib.h>
#define Size 10
int arr[Size];
int hashkey(int value)
{
    return value % Size;
}
void insert(int value)
{
    int key = hashkey(value);
    if (arr[key] == '\0' || arr[key] == -1)
    {
        arr[key] = value;
    }
    else
    {
        int i = (key + 1) % Size;
        while (arr[i] != '\0' && i != key)
        {
            i = (i + 1) % Size;
        }
        if (i == key)
        {
            printf("No Space to fill the given data\n");
            return;
        }
        arr[i] = value;
    }
}
void delete (int value)
{
    int key = hashkey(value);
    if (arr[key] == '\0')
    {
        printf("No value to delete\n");
    }
    else
    {
        arr[key] = -1;
    }
}
void display()
{
    printf("Elements in Heap:\n");
    for (int i = 0; i < Size; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");
}
void search(int value)
{
    int key = hashkey(value);
    if (arr[key] == value)
    {
        printf("!!Value Found!!\n");
    }
    else
    {
        printf("!!Value Not Found!!\n");
    }
}
void main()
{
    int option, value;
    while (1)
    {
        printf("Enter Option\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter Value\n");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            printf("Enter Value for Delete\n");
            scanf("%d", &value);
            delete (value);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Enter Value for Search\n");
            scanf("%d", &value);
            search(value);
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    }
}