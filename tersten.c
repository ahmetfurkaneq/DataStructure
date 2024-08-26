#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insert(struct Node **head_ref, int data)
{
    struct Node *new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}
void reversePrint(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    printf("Bagli listenin elemanlari tersten yazdirildi");
    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }
}

int main()
{

    struct Node *head = NULL;
    int data;
    char choice;

    do
    {
        printf("Bir sayi giriniz:");
        scanf("%d", &data);
        insert(&head, data);
        printf("Devam etmek istiyor musunuz? ...(E/H)");
        scanf("%c", &choice);
    } while (choice == 'E' || choice == 'e');
    // Duz yazdirir
    printList(head);
    printf("\n");
    // Tersten yazdirir
    reversePrint(head);

    return 0;
}
