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

    root = (node *)malloc(sizeof(node));
    root->data = 10;
    root->prev = NULL;
    root->next = (node *)malloc(sizeof(node));
    root->next->prev = root;
    root->next->data = 20;
    root->next->next = (node *)malloc(sizeof(node));
    root->next->next->prev = root->next;
    root->next->next->data = 30;
    root->next->next->next = NULL;

    willbeadded = (node *)malloc(sizeof(node));
    willbeadded->data = 40;
    willbeadded->prev = NULL;
    willbeadded->next = (node *)malloc(sizeof(node));
    willbeadded->next->prev = willbeadded;
    willbeadded->next->data = 50;
    willbeadded->next->next = (node *)malloc(sizeof(node));
    willbeadded->next->next->prev = willbeadded->next;
    willbeadded->next->next->data = 60;
    willbeadded->next->next->next = NULL;

    temp = root;
    printf("Ilk Liste:\n");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    temp2 = willbeadded;

    while (temp2 != NULL)
    {
        printf("%d -> ", temp2->data);
        temp2 = temp2->next;
    }
    printf("NULL\n");

    temp = root;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = willbeadded;
    willbeadded->prev = temp;
    temp = root;
    printf("Birlesik Liste:\n");
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        else
        {

            printf("%d -> ", temp->data);
            temp = temp->next;
        }
    }

    return 0;
}
