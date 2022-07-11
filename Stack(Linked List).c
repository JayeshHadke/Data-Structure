#include <stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *next;
};
typedef struct node *Node;
Node push(Node root, int value)
{
    Node temp = (Node)malloc(sizeof(struct node));
    temp->item = value;
    temp->next = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        Node cur = root;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = temp;
    }
    return root;
}
Node pop(Node root)
{
    if (root == NULL)
    {
        printf("Stack is Underflow\n");
    }
    else
    {
        Node cur = root, prev = NULL;
        while (cur->next != NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        if (prev == NULL)
        {
            root = NULL;
            free(cur);
            return root;
        }
        prev->next = NULL;
        free(cur);
    }
    return root;
}
void display(Node root)
{
    if (root == NULL)
    {
        printf("No elements to display\n");
    }
    else
    {
        Node cur = root;
        while (cur != NULL)
        {
            printf(">>%d", cur->item);
            cur = cur->next;
        }
        printf("\n");
    }
}
void main()
{
    int value, option;
    Node root = NULL;
    while (1)
    {
        printf("Enter Option\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter Value\n");
            scanf("%d", &value);
            root = push(root, value);
            break;
        case 2:
            root = pop(root);
            break;
        case 3:
            display(root);
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
