#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *pointer;
};
struct node *head = NULL;
struct node *temp = NULL;

void addFoot(int sayi)
{
    struct node *willbeadded;
    willbeadded = (struct node *)malloc(sizeof(struct node));
    willbeadded->data = sayi;
    willbeadded->pointer = NULL;
}

if (head == NULL)
{
    head = willbeadded;
}
else
{
    temp = head;
    while (temp->pointer != NULL)
    {
        temp = temp->pointer;
    }
    temp->pointer = willbeadded;
}
}
addBetween(int n, int veri)
{
    struct node *willbeadded;
    willbeadded = (struct node *)malloc(sizeof(struct node));
    willbeadded->data = veri;
}
void yazdir()
{
    temp = head;
    while (temp->pointer != NULL)
    {
        printf("%d", temp->data);
        // printf("%d",temp->pointer);
        temp = temp->pointer;
    }
    printf("%d", temp->data);
}

int main()
{
    int secim,sayi,sira;
    printf("(1)Listenin başına eklemek icin:\n(2)Listenin ortasina eklemek icin\n(3)Listenin sonuna eklemek icin:");
    scanf("%d",&secim);
     switch (secim)
     {
     case 1:{
        addHead(sayi);
        break;
     }
    
     
     default:
        break;
     }

    int sayi, count = 0;

    while (count != 10)
    {
        printf("\n Listeye bir sayi ekleyiniz: \n");
        scanf("%d", &sayi);
        addFoot(sayi);
        count++;
        yazdir();
    }
    return 0;
}