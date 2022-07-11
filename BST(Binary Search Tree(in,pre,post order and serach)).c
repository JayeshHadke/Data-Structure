#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *right;
    int value;
    struct node *left;
};
typedef struct node *Node;
Node insert(Node root, int value)
{
    Node temp = (Node)malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    temp->value = value;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        if (root->value > value)
        {
            root->left = insert(root->left, value);
        }
        else
        {
            root->right = insert(root->right, value);
        }
    }
    return root;
}
void preorder(Node root)
{
    if (root != NULL)
    {
        printf(">>%d", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(">>%d", root->value);
        inorder(root->right);
    }
}
void postorder(Node root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(">>%d", root->value);
    }
}
int search(Node root, int value)
{
    int temp;
    if (root != NULL)
    {
        temp = search(root->left, value);
        temp = search(root->right, value);
        if (root->value == value)
        {
            return 1;
        }
    }
}
void main()
{
    int option, value, temp;
    Node root = NULL;
    while (1)
    {
        printf("--------------------\n");
        printf("Enter Option\n1.Insert\n2.Preorder Transvers\n3.Inorder Transvers\n4.Postorder Transvers\n5.Search\n6.Exit\n");
        printf("--------------------\n");
        scanf("%d", &option);
        printf("--------------------\n");
        switch (option)
        {
        case 1:
            printf("--------------------\n");
            printf("Enter Value\n");
            printf("--------------------\n");
            scanf("%d", &value);
            printf("--------------------\n");
            root = insert(root, value);
            break;
        case 2:
            printf("--------------------\n");
            printf("Preorder Transvers:\n");
            preorder(root);
            printf("\n--------------------\n");
            break;
        case 3:
            printf("--------------------\n");
            printf("Inorder Transvers:\n");
            inorder(root);
            printf("\n--------------------\n");
            break;
        case 4:
            printf("--------------------\n");
            printf("Postorder Transvers:\n");
            postorder(root);
            printf("\n--------------------\n");
            break;
        case 5:
            printf("--------------------\n");
            printf("Enter Value for search\n");
            printf("--------------------\n");
            scanf("%d", &value);
            printf("--------------------\n");
            temp = search(root, value);
            if (temp == 1)
            {
                printf("--------------------\n");
                printf("\n!!Item Found!!\n");
                printf("--------------------\n");
            }
            else
            {
                printf("--------------------\n");
                printf("\n!!Item Not Found!!\n");
                printf("--------------------\n");
            }
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid Input\n");
            break;
        }
    }
}