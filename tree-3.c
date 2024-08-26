#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};


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
    struct node* root = (struct node *)malloc(sizeof(struct node));
    root->data = 8;
    root->left = 4;
    root->left->left = 2;
    root->left->left->right = 3;
    root->left->right = 5;
    root->left->right->right = 7;
    root->right = 12;
    root->right->left = 9;
    root->right->left->right = 10;
    root->right->right = 14;



















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