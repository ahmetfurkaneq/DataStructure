#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *temp = NULL;
struct node *prev = NULL;
struct node *last = NULL;

void addHead(int sayi)
{
    struct node *willbeadded = (struct node *)malloc(sizeof(struct node));
    willbeadded->data = sayi;
    if (head == NULL)
    {
        head = willbeadded;
        head->next = head;
    }
    else
    {
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = willbeadded;
        willbeadded->next = head;
        head = willbeadded;
    }

    void addFoot(int sayi)
    {
        struct node *willbeadded = (struct node *)malloc(sizeof(struct node));
        willbeadded->data = sayi;
        if (head == NULL)
        {
            head = willbeadded;
            head->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = willbeadded;
            willbeadded->next = head;
        }
    }
    void delFromHead()
    {
        if (head = NULL)
        {
            printf("Silinecek eleman yok");
        }
        else
        {
            if (head->next == head)
            {
                free(head);
                head = NULL;
            }
            else
            {
                last = head;
                while (last->next != head)
                {
                    last = last->next;
                }
                temp = last;
                free(last->next);
                last->next = head;
            }
        }
    }
    void delFromFoot()
    {
        if (head = NULL)
        {
            printf("Silinecek eleman yok");
        }
        else
        {
            if (head->next == head)
            {
                free(head);
                head = NULL;
            }
            else
            {
                last = head;
                while (last->next->next != head)
                {
                    last = last->next;
                }
                temp = last;
                free(last->next);
                last->next = head;
            }
        }
    }
    void liste()
    {
        system("cls");
        if (head = NULL)
        {
            printf("Gösterilecek eleman yok");
        }
        else
            temp = head;

        while (temp->next != head)
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
    void istenendDugumuSil(int sayi)
    {
        if (head = NULL)
        {
            return;
        }
        struct node *temp = head;
        if (temp->data == sayi)
        {
            head = temp->next;
            free(temp);
            return;
        }
        struct node *prev = NULL;
        while (temp != NULL && temp->data != sayi)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;

        prev->next = temp->next;
        free(temp);
    }


    int main(){
        while (1)
        {
            
            int secim 
                    }
        
    }
