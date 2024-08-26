#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *node, int data)
{
    if (node == NULL)
        return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data >= node->data)
    {
        node->right = insert(node->right, data);
    }
    return node;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (root->data <= key)
    {
        return search(root->right, key);
    }
    else
        return search(root->left, key);
}

struct Node *findMin(struct Node *node)
{
    struct Node *current = node;
    while (current && current->left != NULL)
    {
        return current;
    }
}

struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key >= root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 90);
    root = insert(root, 100);

    printf("Olusturulan agacta Preorder gezinme : ");
    preorder(root);
    printf("\n");

    printf("Olusturulan agacta ineorder gezinme : ");
    inorder(root);
    printf("\n");

    printf("Olusturulan agacta postorder gezinme : ");
    postorder(root);
    printf("\n");

    printf("20 Silinecek\n");
    root = deleteNode(root, 20);
    printf("20 degeri silindikten sonra preorder : ");
    preorder(root);
    printf("\n");
    printf("20 degeri silindikten sonra inorder : ");
    inorder(root);
    printf("\n");
    printf("20 degeri silindikten sonra postorder : ");
    postorder(root);
    printf("\n");

    printf("30 Silinecek\n");
    root = deleteNode(root, 30);
    printf("30 degeri silindikten sonra preorder : ");
    preorder(root);
    printf("\n");
    printf("30 degeri silindikten sonra inorder : ");
    inorder(root);
    printf("\n");
    printf("30 degeri silindikten sonra postorder : ");
    postorder(root);
    printf("\n");

    struct Node *foundNode = search(root, 60);
    if (foundNode != NULL)
    {
        printf("BTS Agacta 60 degeri bulundu.\n");
    }
    else
    {
        printf("BST Agacta 60 degeri bulunamadi.\n");
    }
    return 0;
}