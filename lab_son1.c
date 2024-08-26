// Cift dogrusal listelerde listenin sonuna dugum ekleyen method

#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node addFoot(root){}



int main()
{
    Node *root = NULL;
    root = (Node *)malloc(sizeof(Node));
    root->data = 25;
    root->prev = NULL;
    root->next = (Node *)malloc(sizeof(Node));
    root->next->data = 10;
    root->next->prev = 25;
    root->next->next = (Node *)malloc(sizeof(Node));
    root->next->next->data = 15;
    root->next->next->prev = 10;
    root->next->next->next = (Node *)malloc(sizeof(Node));
    root->next->next->next->data = 255;
    root->next->next->next->prev = 15;
    root->next->next->next->next = NULL;
}