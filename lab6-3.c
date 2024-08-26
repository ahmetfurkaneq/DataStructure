#include <stdio.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *next = NULL;
struct node *head = NULL;
struct node *temp = NULL;
struct node *prev = NULL;
struct node *temp2 = NULL;

void addHead(int sayi)
{
    struct node *willbeadded = (struct node *)malloc(sizeof(struct node));
    willbeadded->prev = NULL;
    willbeadded->data = sayi;
    if (head == NULL)
    {
        head = willbeadded;
        head->next = NULL;
    }
    else
    {
        willbeadded->next = head;
        head->prev = willbeadded;
        head = willbeadded;
    }
}
void addFoot(int sayi)
{
    struct node *willbeadded = (struct node *)malloc(sizeof(struct node));
    willbeadded->data = sayi;
    willbeadded->next = NULL;
    if (head == NULL)
    {
        head = willbeadded;
        //      head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        if (head->next == NULL)
        {
            head->next = willbeadded;
            willbeadded->prev = head;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = willbeadded;
            willbeadded->prev = temp;
        }
    }
}
void addBetween(int sira, int sayi)
{
    struct node *willbeadded = (struct node *)malloc(sizeof(struct node));
    willbeadded->data = sayi;
    willbeadded->next = NULL;
    int i = 0;
    if (head == NULL)
    {
        head = willbeadded;
        //      head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        if (head->next == NULL)
        {
            head->next = willbeadded;
            willbeadded->prev = head;
        }
        else
        {
            temp = head;
            while (i < sira - 1)
            {
                temp = temp->next;
            }
            willbeadded->next = temp->next;
            willbeadded->prev = temp;
            temp->next = willbeadded;
            temp2 = temp->next;
            temp2->prev = willbeadded;
        }
    }
}
void delFromHead()
{
    if (head == NULL)
    {
        printf("Listede silinecek yok");
    }
    else
    {
        if (head->next != NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            temp = head->next;
            free(head);
            temp->prev = NULL;
            head = temp;
        }
    }
}

void delFromFoot()
{
    if (head == NULL)
    {
        printf("Silinecek bisi yok");
    }
    else
    {
        if (head->next == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            temp = head;
            while (temp = head)
            {
                while (temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                temp2 = temp;
                free(temp->next);
            }
        }
    }
}

void liste()
{
    system("cls");
    if (head == NULL)
    {
        printf("Bos liste");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}

int main()
{
    while (1)
    {
        int secim, sayi, sira;
        printf("\nCift Yonlu Liste Basina Eleman Eklemek İcin 1:\n");
        printf("Cift Yonlu Liste Sonuna Eleman Eklemek İcin 2:\n");
        printf("Cift Yonlu Liste Basindan Eleman Silmek İcin 3:\n");
        printf("Cift Yonlu Liste Sonundan Eleman Silmek  İcin 4:\n");
        printf("Cift Yonlu Listeyi Yazdirmak icin 5:\n");
        scanf("%d", &secim);
        switch (secim)
        {
        case 1:
        {
            printf("\n Liste basina Eklenecek sayiyi giriniz:");
            scanf("%d", &sayi);
            addHead(sayi);
            break;
        }
        case 2:
        {
            printf("\n Liste Sonuna Eklenecek sayiyi giriniz:");
            scanf("%d", &sayi);
            addFoot(sayi);
            break;
        }
        case 3:
        {
            delFromHead(sayi);
            break;
        }
        case 4:
        {
            delFromFoot(sayi);
            break;
        }
        case 5:
        {
            liste();
            break;
        }
        case 6:
        {
            printf("Kacinci siraya ekleme yapılacak");
            scanf("%d", &sira);
            printf("\n Listeye Eklenecek sayiyi giriniz:");
            scanf("%d", &sayi);
            addBetween(sira, sayi);
        }
        default:
            break;
        }
    }
}