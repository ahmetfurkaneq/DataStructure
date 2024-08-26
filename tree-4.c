#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right, *parent;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

Node* insertNode(Node* node, Node* parent, int data) {
    if (node == NULL) {
        Node *newNode = createNode(data);
        newNode->parent = parent;
        return newNode;
    }

    if (data < node->data)
        node->left = insertNode(node->left, node, data);
    else if (data > node->data)
        node->right = insertNode(node->right, node, data);

    return node;
}

int findHeight(Node* node) {
    if (node == NULL) return -1;
    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int countNodes(Node* node) {
    if (node == NULL) return 0;
    return countNodes(node->left) + countNodes(node->right) + 1;
}

void printLeafNodes(Node* node) {
    if (node != NULL) {
        if (node->left == NULL && node->right == NULL)
            printf("%d ", node->data);
        printLeafNodes(node->left);
        printLeafNodes(node->right);
    }
}

void printAncestors(Node *node, int x) {
    if (node == NULL) return;
    if (node->data == x) {
        Node *temp = node;
        while (temp->parent != NULL) {
            printf("%d ", temp->parent->data);
            temp = temp->parent;
        }
        printf("\n");
    } else {
        printAncestors(node->left, x);
        printAncestors(node->right, x);
    }
}

void printSiblings(Node *node, int y) {
    if (node == NULL) return;
    if (node->left != NULL && node->left->data == y && node->right != NULL) {
        printf("%d ", node->right->data);
    } else if (node->right != NULL && node->right->data == y && node->left != NULL) {
        printf("%d ", node->left->data);
    }
    printSiblings(node->left, y);
    printSiblings(node->right, y);
}

void printDepthHeight(Node *node, int z) {
    static int depth = -1, height = -1;
    if (node == NULL) return;
    depth++;
    if (node->data == z) {
        printf("Depth: %d, ", depth);
        height = findHeight(node);
        printf("Height: %d\n", height);
    }
    printDepthHeight(node->left, z);
    printDepthHeight(node->right, z);
    depth--;
}

int main() {
    Node *root = NULL;
    root = insertNode(root, NULL, 8);
    insertNode(root, NULL, 4);
    insertNode(root, NULL, 12);
    insertNode(root, NULL, 2);
    insertNode(root, NULL, 5);
    insertNode(root, NULL, 9);
    insertNode(root, NULL, 14);
    insertNode(root, NULL, 3);
    insertNode(root, NULL, 7);
    insertNode(root, NULL, 10);

    printf("Agactaki toplam dugum sayisi: %d\n", countNodes(root));
    printf("Yukseklik: %d\n", findHeight(root));
    printf("Kok dugumun degeri: %d\n", root->data);
    printf("Yapraklarin degerleri: ");
    printLeafNodes(root);
    printf("\n");

    int x = 10, y = 5, z = 9;
    printf("%d degerine sahip dugumun ebeveyni : ", x);
    printAncestors(root, x);
    printf("%d degerine sahip dugumun kardesleri %d: ", y);
    printSiblings(root, y);
    printf("\n");
    printf("%d degerine sahip dugumun derinligi: ", z);
    printDepthHeight(root, z);

    return 0;
}
