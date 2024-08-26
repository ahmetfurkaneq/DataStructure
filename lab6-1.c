//Tek yonlu dogrusal bir listeyi ,tek yönlü dairesel listeye çeviren c methodu
//Bu islem icin ekle() metodu kullanılır


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
    if (root=)
    {
        /* code */
    }
    
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
Node *deleteFirst(Node *root)
{
    if (root == NULL)
    {
        printf("Liste bos.\n");
        return NULL;
    }
    Node *temp = root;
    root = root->next;
    free(temp);
    return root;
}

Node *deleteLast(Node *root)
{
    if (root == NULL)
    {
        printf("Liste bos.\n");
        return NULL;
    }
    if (root->next == NULL)
    {
        free(root);
        return NULL;
    }
    Node *temp = root;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return root;
}
void *find(Node *root, int value)
{
    if (root == NULL)
    {
        printf("Liste bos.\n");
        return NULL;
    }
    if (root->data == value)
    {
        Node *temp = root;
        root = root->next;
        printf("%d", value);
    }
    Node *temp = root;
    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
        if (root->data == value)
        {
            Node *temp = root;
            root = root->next;
            printf("%d", value);
        }
    }
    printf("Aradiginiz veri bulundu :%d", &value);
    if (temp->next == NULL)
    {
        printf("Listede veri bulunamadi.\n");
    }
}
Node *deleteValue(Node *root, int value)
{
    if (root == NULL)
    {
        printf("Liste bos.\n");
        return NULL;
    }
    if (root->data == value)
    {
        Node *temp = root;
        root = root->next;
        free(temp);
        return root;
    }
    Node *temp = root;
    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Listede veri bulunamadi.\n");
        return root;
    }
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
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
    int i = 0;
    while (i == 0)
    {
        printf("\n1. Basa Ekle\n2. Araya Ekle\n3. Sona Ekle\n4. Listeyi Yazdir\n5. Silinmesini istediginiz veriyi giriniz\n6.Ilk veriyi silmek icin\n7.Son veriyi silmek icin\n8.Veri Aramak icin \nSecenek: ");
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
            printf("Aranacak sayiyi giriniz:");
            scanf("%d", &data);
            find(root, data);
            break;
        }

        i = 0;
    }
    return 0;
}