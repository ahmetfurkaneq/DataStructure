#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
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
    if (root == NULL)
        return;
    Node *temp = root;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != root);
    printf("\n");
}

Node *addHead(Node *root, int data)
{
    Node *newNode = createNode(data);
    if (root == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    Node *temp = root;
    while (temp->next != root)
    {
        temp = temp->next;
    }
    newNode->next = root;
    temp->next = newNode;
    return newNode;
}

Node *addBetween(Node *root, int data, int position)
{
    if (root == NULL)
        return NULL;
    Node *newNode = createNode(data);
    Node *temp = root;
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
        if (temp == root)
        {
            printf("Listede yeterli eleman yok.\n");
            return root;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return root;
}

Node *addFoot(Node *root, int data)
{

    if (root == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    Node *temp = root;
    while (temp->next != root)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = root;
    return root;
}

Node *deleteFirst(Node *root)
{
    if (root == NULL)
        return NULL;
    if (root->next == root)
    {
        free(root);
        return NULL;
    }
    Node *temp = root->next;
    Node *last = root;
    while (last->next != root)
        last = last->next;
    last->next = temp;
    free(root);
    return temp;
}

Node *deleteLast(Node *root)
{
    if (root == NULL)
        return NULL;
    if (root->next == root)
    {
        free(root);
        return NULL;
    }
    Node *current = root;
    while (current->next->next != root)
    {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = root;
    free(temp);
    return root;
}

Node *deleteValue(Node *root, int value)
{
    if (root == NULL)
        return NULL;
    if (root->data == value && root->next == root)
    {
        free(root);
        return NULL;
    }
    Node *current = root;
    Node *prev = NULL;
    do
    {
        if (current->data == value)
        {
            if (prev == NULL)
            {
                return deleteFirst(root);
            }
            prev->next = current->next;
            free(current);
            return root;
        }
        prev = current;
        current = current->next;
    } while (current != root);
    printf("Listede veri bulunamadi.\n");
    return root;
}

void find(Node *root, int value)
{
    if (root == NULL)
    {
        printf("Liste bos.\n");
        return;
    }
    Node *temp = root;
    do
    {
        if (temp->data == value)
        {
            printf("Aradiginiz veri bulundu: %d\n", value);
            return;
        }
        temp = temp->next;
    } while (temp != root);
    printf("Listede veri bulunamadi.\n");
}

int main()
{
    Node *root = NULL;
    int secim, data, position;
    while (1)
    {
        printf("\n1. Basa Ekle\n2. Araya Ekle\n3. Sona Ekle\n4. Listeyi Yazdir\n5. Silinmesini istediginiz veriyi giriniz\n6. Ilk veriyi silmek icin\n7. Son veriyi silmek icin\n8. Veri Aramak icin \nSecenek: ");
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
            printf("Liste: ");
            yazdir(root);
            break;
        case 5:
            printf("Silinmesini istediginiz veriyi giriniz: ");
            scanf("%d", &data);
            root = deleteValue(root, data);
            break;
        case 6:
            root = deleteFirst(root);
            break;
        case 7:
            root = deleteLast(root);
            break;
        case 8:
            printf("Aranacak sayiyi giriniz: ");
            scanf("%d", &data);
            find(root, data);
            break;
        }
    }
    return 0;
}
