#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;



int main()
{
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

    willbeadded = (node *)malloc(sizeof(node));
    willbeadded->data = 40;
    willbeadded->next = (node *)malloc(sizeof(node));
    willbeadded->next->data = 50;
    willbeadded->next->next = (node *)malloc(sizeof(node));
    willbeadded->next->next->data = 60;
    willbeadded->next->next->next = NULL;

    temp = root;
    temp2 = willbeadded;
    while (root != NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
    temp->next = willbeadded;
    willbeadded->prev = temp;

    while (temp2 != NULL)
    {
        printf("\n%d->", temp2->data);
        temp2 = temp2->next;
    }

    temp = root;
    while (temp->next!=NULL)
    {
         temp = temp->next;
    }
     temp->next = willbeadded;
    willbeadded->prev = temp;

     while (root != NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
    
}
