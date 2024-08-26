#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node;

node *willbeadded = NULL;
node *root = NULL;
node *temp = NULL;
node *temp2 = NULL;


void degistir()
{
}

int main()
{
    struct node *root;
    node *willbeadded = NULL;
    node *root = NULL;
    node *temp = NULL;
    node *temp2 = NULL;
    root->prev = NULL;
    root = (node *)malloc(sizeof(node));
    root->data = 10;
    root->next = (node *)malloc(sizeof(node));
    root->next->data = 20;
    root->next->next = (node *)malloc(sizeof(node));
    root->next->next->data = 30;
    root->next->next->next = NULL;
}