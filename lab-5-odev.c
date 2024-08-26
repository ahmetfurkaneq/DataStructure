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
    if (!newNode)
    {
        perror("Memory allocation failed");
        return NULL;
    }
    newNode->data = data;
    newNode->next = newNode->prev = newNode; // Node points to itself initially
    return newNode;
}

Node *addHead(Node *root, int data)
{
    Node *newNode = createNode(data);
    if (!newNode)
        return root;

    if (root == NULL)
    {
        return newNode;
    }

    Node *tail = root->prev; // Get the last node
    newNode->next = root;
    newNode->prev = tail;
    root->prev = newNode;
    tail->next = newNode;
    return newNode; // newNode becomes the new head
}

Node *addBetween(Node *root, int data, int position)
{
    if (root == NULL || position < 1)
        return NULL;

    Node *newNode = createNode(data);
    if (!newNode)
        return root;

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
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    return root;
}

Node *addFoot(Node *root, int data)
{
    if (root == NULL)
    {
        return addHead(root, data); // Reuse addHead if list is empty
    }

    Node *newNode = createNode(data);
    if (!newNode)
        return root;

    Node *tail = root->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = root;
    root->prev = newNode;
    return root;
}

Node *deleteFirst(Node *root)
{
    if (root == NULL || root->next == root)
    {
        free(root);
        return NULL;
    }

    Node *newHead = root->next;
    newHead->prev = root->prev;
    root->prev->next = newHead;
    free(root);
    return newHead;
}

Node *deleteLast(Node *root)
{
    if (root == NULL || root->next == root)
    {
        return deleteFirst(root); // Reuse deleteFirst if only one node
    }

    Node *last = root->prev;
    last->prev->next = root;
    root->prev = last->prev;
    free(last);
    return root;
}

Node *deleteValue(Node *root, int value)
{
    if (root == NULL)
        return NULL;

    Node *current = root;
    do
    {
        if (current->data == value)
        {
            if (current == root)
            {
                return deleteFirst(root);
            }
            else if (current->next == root)
            {
                return deleteLast(root);
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                free(current);
                return root;
            }
        }
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

void yazdir(Node *root)
{
    if (root == NULL)
    {
        printf("Liste bos.\n");
        return;
    }
    Node *temp = root;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != root);
    printf("\n");
}

void swapFirstLastPairs(Node **root)
{
    if (*root == NULL || (*root)->next == *root || (*root)->next->next == *root)
    {
        return; // Listede yeterli eleman yoksa dön
    }

    Node *first = *root;
    Node *second = first->next;
    Node *last = (*root)->prev;
    Node *secondLast = last->prev;

    if (second == last || secondLast == first)
    {
        return; // Liste 3 elemanlıysa işlem yapmamalı
    }

    // Yer değiştirme işlemi burada yapılacak
    if (second->next == last)
    { // Liste dört elemanlıysa
        first->next = last;
        last->prev = first;
        second->prev = secondLast;
        secondLast->next = second;
        second->next = first;
        first->prev = second;
        last->next = second;
        second->prev = last;
    }
    else
    {
        // Normal durum
        secondLast->next = first;
        first->prev = secondLast;
        last->prev = second;
        second->next = last;
        first->next = second->next;
        second->next->prev = first;
        second->next = first;
        first->prev = second;
        last->next = *root;
        (*root)->prev = last;
    }

    // Kök düğüm değiştiyse güncelle
    *root = last;
}

int main()
{
    Node *root = NULL;
    int secim, data, position;
    while (1)
    {
        printf("\n1. Basa Ekle\n2. Araya Ekle\n3. Sona Ekle\n4. Listeyi Yazdir\n5. Silinmesini istediginiz veriyi giriniz\n6. Ilk veriyi silmek icin\n7. Son veriyi silmek icin\n8. Veri Aramak icin\n9. İlk ve son 2 node'u değiştir\nSecenek: ");
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
        case 9:
            swapFirstLastPairs(&root);
            break;
        }
    }
    return 0;
}
