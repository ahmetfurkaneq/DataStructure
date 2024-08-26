#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;

Node *newNode(int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int treeHeight(Node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void findLeaves(Node *root, int *leaves, int *count)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        leaves[(*count)++] = root->data;
    }
    findLeaves(root->left, leaves, count);
    findLeaves(root->right, leaves, count);
}

bool findAncestors(Node *root, int x, int *ancestors, int *count)
{
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;
    if (findAncestors(root->left, x, ancestors, count) || findAncestors(root->right, x, ancestors, count))
    {
        ancestors[(*count)++] = root->data;
        return true;
    }
    return false;
}

void findSiblings(Node *root, int x, int *siblings, int *count)
{
    if (root == NULL || root->data == x)
        return;
    Node *current;
    Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear)
    {
        current = queue[front++];
        if (current->left && current->right)
        {
            if (current->left->data == x)
            {
                siblings[(*count)++] = current->right->data;
                return;
            }
            if (current->right->data == x)
            {
                siblings[(*count)++] = current->left->data;
                return;
            }
        }
        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
}

bool findDepthAndHeight(Node *root, int x, int depth, int *nodeDepth, int *nodeHeight)
{
    if (root == NULL)
        return false;
    if (root->data == x)
    {
        *nodeDepth = depth;
        *nodeHeight = treeHeight(root) - 1;
        return true;
    }
    return findDepthAndHeight(root->left, x, depth + 1, nodeDepth, nodeHeight) || findDepthAndHeight(root->right, x, depth + 1, nodeDepth, nodeHeight);
}

void displayMenu()
{
    printf("\nMenu:\n");
    printf("1. Toplam Dugum\n");
    printf("2. Agac Yuksekligi\n");
    printf("3. Kok degeri\n");
    printf("4. Yaprak Dugumler\n");
    printf("5. Bir Dugumun Atalari\n");
    printf("6. Bir Dugumun Kardesleri\n");
    printf("7. Bir Dugumun Derinligi ve Yuksekligi\n");
    printf("8. Cikis\n");
    printf("Seciminiz: ");
}

int main()
{
    Node *root = newNode(8);
    root->left = newNode(4);
    root->right = newNode(12);
    root->left->left = newNode(2);
    root->left->right = newNode(5);
    root->left->right->right = newNode(7);
    root->right->left = newNode(9);
    root->right->right = newNode(14);
    root->left->left->left = newNode(3);
    root->right->left->right = newNode(10);

    int choice, value;
    while (1)
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Toplam dugum: %d\n", countNodes(root));
            break;

        case 2:
            printf("Agac Yuksekligi: %d\n", treeHeight(root));
            break;

        case 3:
            printf("Kok Degeri: %d\n", root->data);
            break;

        case 4:
        {
            int leaves[100];
            int leafCount = 0;
            findLeaves(root, leaves, &leafCount);
            printf("Yaprak Dugumler: ");
            for (int i = 0; i < leafCount; i++)
            {
                printf("%d ", leaves[i]);
            }
            printf("\n");
            break;
        }

        case 5:
        {
            printf("Atalari bulmak icin istenen degeri giriniz: ");
            scanf("%d", &value);
            int ancestors[100];
            int ancestorCount = 0;
            if (findAncestors(root, value, ancestors, &ancestorCount))
            {
                printf("%d degerinin atalari: ", value);
                for (int i = 0; i < ancestorCount; i++)
                {
                    printf("%d ", ancestors[i]);
                }
                printf("\n");
            }
            else
            {
                printf("%d bulunamadi.\n", value);
            }
            break;
        }

        case 6:
        {
            printf("Kardesleri bulunacak degerleri giriniz: ");
            scanf("%d", &value);
            int siblings[100];
            int siblingCount = 0;
            findSiblings(root, value, siblings, &siblingCount);
            if (siblingCount > 0)
            {
                printf("%d kardesleri: ", value);
                for (int i = 0; i < siblingCount; i++)
                {
                    printf("%d ", siblings[i]);
                }
                printf("\n");
            }
            else
            {
                printf("Degerin Kardesi yok ya da deger bulunamadi.\n", value);
            }
            break;
        }

        case 7:
        {
            printf("Derinlik ve yuksekligini bulmak istediginiz dugumun degerini giriniz: ");
            scanf("%d", &value);
            int nodeDepth = 0, nodeHeight = 0;
            if (findDepthAndHeight(root, value, 0, &nodeDepth, &nodeHeight))
            {
                printf("Derinlik %d: %d, Yukseklik: %d\n", value, nodeDepth, nodeHeight + 1);
            }
            else
            {
                printf("Dugum bulunamadi.\n", value);
            }
            break;
        }

        case 8:
            exit(0);

        default:
            printf("Yanlis Secim Tekrar giriniz:.\n");
        }
    }
    return 0;
}