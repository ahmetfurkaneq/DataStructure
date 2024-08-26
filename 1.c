#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *temp = NULL;
struct node *front = NULL;
struct node *rear = NULL;

void tekyazdir(struct node *nd) {
    printf("\n data : %d", nd->data);
    printf("\n adres : %p", (void *)nd);
}

void enqueue(int x) {
    struct node *willbeadded = (struct node *)malloc(sizeof(struct node));
    willbeadded->data = x;
    willbeadded->next = NULL;
    willbeadded->prev = NULL;

    if (front == NULL) {
        front = willbeadded;
        rear = willbeadded;
        tekyazdir(willbeadded);
    } else {
        rear->next = willbeadded;
        willbeadded->prev = rear;
        rear = willbeadded;
        tekyazdir(willbeadded);
    }
}

int dequeue() {
    if (front == NULL) {
        printf("Kuyruk Bos..\n");
        return -1; // Return a value to indicate queue is empty
    } else {
        int data = front->data;
        temp = front;
        front = front->next;
        if (front != NULL) {
            front->prev = NULL;
        } else {
            rear = NULL;
        }
        free(temp);
        return data;
    }
}

void printqueue() {
    system("cls");
    if (front == NULL) {
        printf("Kuyrukta yazdırılacak eleman yok...\n");
    } else {
        temp = front;
        while (temp != NULL) {
            printf("%d \n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int sec, n;
    while (1) {
        printf("Kuyruga eleman eklemek icin Enqueue :1 \n");
        printf("Kuyruktan eleman Cikarmak icin Dequeue :2 \n");
        printf("Ekrana yazdirmak icin :3 \n");
        printf("Secim yapiniz :");
        scanf("%d", &sec);
        switch (sec) {
            case 1:
                printf("Eklenecek Sayiyi giriniz:");
                scanf("%d", &n);
                enqueue(n);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printqueue();
                break;
            default:
                printf("Gecersiz secim.\n");
                break;
        }
    }
    return 0;
}
