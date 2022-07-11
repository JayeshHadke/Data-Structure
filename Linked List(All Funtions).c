#include <stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *next;
};
typedef struct node *Node;
Node insertfront(Node root, int value)
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
        temp->next = root;
        root = temp;
    }
    return root;
}
Node insertrare(Node root, int value)
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
Node insertposition(Node root, int position, int value)
{
    Node temp = (Node)malloc(sizeof(struct node));
    temp->item = value;
    temp->next = NULL;
    if (position == 1)
    {
        temp->next = root;
        root = temp;
    }
    else
    {
        int pos = 1;
        Node cur = root, prev = NULL;
        while (cur != NULL)
        {
            if (pos == position)
            {
                break;
            }
            pos++;
            prev = cur;
            cur = cur->next;
        }
        temp->next = prev->next;
        prev->next = temp;
    }
    return root;
}
Node deletefront(Node root)
{
    if (root == NULL)
    {
        printf("Linked List is Empty\n");
    }
    else
    {
        Node cur = root;
        root = root->next;
        free(cur);
    }
    return root;
}
Node deleterare(Node root)
{
    if (root == NULL)
    {
        printf("Linked List is Empty\n");
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
Node deleteposition(Node root, int position)
{
    if (root == NULL)
    {
        printf("No Elements to delete in Linked List\n");
    }
    else if (position == 1)
    {
        Node cur = root;
        root = root->next;
        free(cur);
    }
    else
    {
        int pos = 1;
        Node cur = root, prev = NULL;
        while (cur != NULL)
        {
            if (pos == position)
            {
                break;
            }
            pos++;
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        free(cur);
    }
    return root;
}
Node deleteitem(Node root, int value)
{
    if (root == NULL)
    {
        printf("No Element to delete in Linked List\n");
    }
    else
    {
        if (root->item == value)
        {
            root = deletefront(root);
        }
        else
        {
            Node cur = root, prev = NULL;
            while (cur != NULL)
            {
                if (cur->item == value)
                {
                    break;
                }
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            free(cur);
        }
    }
    return root;
}
void display(Node root)
{
    if (root == NULL)
    {
        printf("Linked List is Empty\n");
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
        printf("Enter Option\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter Option\n1.Insert Front\n2.Insert Rare\n3.Insert at Position\n");
            scanf("%d", &option);
            printf("Enter Value\n");
            scanf("%d", &value);
            switch (option)
            {
            case 1:
                root = insertfront(root, value);
                break;
            case 2:
                root = insertrare(root, value);
                break;
            case 3:
                printf("Enter Position\n");
                scanf("%d", &option);
                root = insertposition(root, option, value);
                break;
            default:
                printf("Invalid Input\n");
                break;
            }
            break;
        case 2:
            printf("Enter Option\n1.Delete Front\n2.Delete Rare\n3.Delete Position Element\n4.Delete Item\n");
            scanf("%d", &option);
            switch (option)
            {
            case 1:
                root = deletefront(root);
                break;
            case 2:
                root = deleterare(root);
                break;
            case 3:
                printf("Enter Element Position\n");
                scanf("%d", &option);
                root = deleteposition(root, option);
                break;
            case 4:
                printf("Enter Value\n");
                scanf("%d", &value);
                root = deleteitem(root, value);
                break;
            default:
                printf("Invalid Input\n");
                break;
            }
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
