#include <stdio.h>
#include <stdlib.h>

// Tek yönlü dairesel bağlı listeler için düğüm yapısı
struct node
{
    int data;
    struct node *next;
};

// Global değişken: başlangıç düğümü (head)
struct node *head = NULL;

// Yeni bir düğüm oluşturup veri ekleyen fonksiyon
void insertNode(int value)
{
    // Yeni bir düğüm oluştur
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;

    // Eğer liste boşsa, yeni düğümü başa ekle
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        // Liste doluysa, yeni düğümü listenin sonuna ekle
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Verilen değeri içeren düğümü arayan fonksiyon
struct node *searchNode(int value)
{
    // Liste boşsa, arama yapılamaz
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    // Liste doluysa, baştan başla ve değeri ara
    struct node *current = head;
    do
    {
        if (current->data == value)
        {
            printf("%d found in the list.\n", value);
            return current;
        }
        current = current->next;
    } while (current != head);

    // Değer bulunamadıysa
    printf("%d not found in the list.\n", value);
    return NULL;
}

// Verilen değeri içeren düğümü silen fonksiyon
void deleteNode(int value)
{
    // Silinecek düğümü bul
    struct node *toDelete = searchNode(value);
    if (toDelete == NULL)
    {
        printf("Cannot delete. Node not found.\n");
        return;
    }

    // Silinecek düğümün önceki düğümünü bul
    struct node *prev = head;
    while (prev->next != toDelete)
    {
        prev = prev->next;
    }

    // Eğer silinecek düğüm baştaysa
    if (toDelete == head)
    {
        // Tek düğüm varsa
        if (toDelete->next == head)
        {
            free(toDelete);
            head = NULL;
        }
        else
        {
            // Son düğümü sil
            prev->next = head->next;
            free(toDelete);
            head = prev->next;
        }
    }
    else
    {
        // Arada ya da sondaysa
        prev->next = toDelete->next;
        free(toDelete);
    }

    printf("%d deleted from the list.\n", value);
}

// Bağlı listeyi ekrana yazdıran fonksiyon
void printList()
{
    // Liste boşsa, ekrana hiçbir şey yazdırma
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct node *current = head;
    // Liste baştan sona dolaşırken, düğüm değerlerini ekrana yazdır
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main()
{
    int choice, value;

    do
    {
        // Menüyü yazdır
        printf("\nCircular Linked List Operations\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Print\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insertNode(value);
            break;
        case 2:
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            deleteNode(value);
            break;
        case 3:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            searchNode(value);
            break;
        case 4:
            printf("Current List: ");
            printList();
            break;
        case 0:
            printf("Cikis yapiliyor....\n");
            break;
        default:
            printf("Hatali giris.\n");
        }
    } while (choice != 0);

    // Tüm düğümleri serbest bırak
    struct node *current = head;
    if (current != NULL)
    {
        struct node *temp;
        do
        {
            temp = current->next;
            free(current);
            current = temp;
        } while (current != head);
    }

    return 0;
}
