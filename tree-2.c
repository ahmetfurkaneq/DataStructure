#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node BTREE;
BTREE *newNode(int data)
{
    BTREE *p = (BTREE *)malloc(sizeof(BTREE));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
BTREE *insert(BTREE *root, int data)
{
    if (root != NULL)
    {
        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else
            root->right = insert(root->right, data);
    }
    else
        root = newNode(data);
    return root;
}

void preorder(BTREE *root)
{
    if (root != NULL)
    {
        printf("%3d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(BTREE *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%3d", root->data);
        inorder(root->right);
    }
}
void postorder(BTREE *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%3d", root->data);
    }
}

int main()
{
    BTREE *myroot = NULL;
    int i = 0;
    do
    {
        printf("\n\nAgaca veri eklemek icin sayi giriniz");
        scanf("%d", &i);
        if (i != -1)
        {
            myroot = insert(myroot, i);
        }

    } while (i != -1);

    printf("\n Pre Order");
    preorder(myroot);
    getch();
    printf("\n In Order");
    inorder(myroot);
    getch();
    printf("\n Post Order");
    inorder(myroot);

    return 0;
}


//+ -> / -> 1 -> 