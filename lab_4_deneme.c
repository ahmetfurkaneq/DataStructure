#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void yazdir(Node *root)
{
    while (root != NULL)
    {
        printf("%d ", root->data);
        root = root->next;
    }
    printf("\n");
}

Node *addHead(Node *root, int data)
{
    Node *newNode = createNode(data);
    newNode->next = root;
    return newNode;
}

Node *addBetween(Node *root, int data, int position)
{
    Node *newNode = createNode(data);
    Node *temp = root;
    for (int i = 0; i < position - 2; i++)
    {
        if (temp == NULL)
        {
            printf("Listede yeterli eleman yok.\n");
            return root;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Listede yeterli eleman yok.\n");
        return root;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return root;
}

// Bağlı listeye sona ekleme
Node *addFoot(Node *root, int data)
{
    Node *newNode = createNode(data);
    if (root == NULL)
    {
        return newNode;
    }
    Node *temp = root;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return root;
}

int main()
{
    Node *root = NULL;
    int secim, data, position;

    while ()
    {
        printf("\n1. Basa Ekle\n2. Ortaya Ekle\n3. Sona Ekle\n4. Listeyi Yazdir \nSecenek: ");
        scanf("%d", &secim);

        switch (secim)
        {
        case 1:
            printf("Eklenecek veri: ");
            scanf("%d", &data);
            root = addHead(root, data);
            break;
        case 2:
            printf("Eklenecek veri: ");
            scanf("%d", &data);
            printf("Eklenecek pozisyon: ");
            scanf("%d", &position);
            root = addBetween(root, data, position);
            break;
        case 3:
            printf("Eklenecek veri: ");
            scanf("%d", &data);
            root = addFoot(root, data);
            break;
        case 4:
            printf("")
         case 5:
            printf("Liste: ");
            yazdir(root);
            break;
        }

        return 0;
    }
}