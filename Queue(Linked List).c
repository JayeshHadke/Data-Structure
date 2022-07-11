#include <stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *next;
};
typedef struct node *Node;
Node enqueue(Node root, int value)
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
Node dequeue(Node root)
{
    if (root == NULL)
    {
        printf("Queue is Underflow\n");
    }
    else
    {
        Node cur = root;
        root = root->next;
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
        printf("Enter Option\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter Value\n");
            scanf("%d", &value);
            root = enqueue(root, value);
            break;
        case 2:
            root = dequeue(root);
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
