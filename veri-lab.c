#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* child;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = temp->child = NULL;
    return temp;
}

void Duzlestir(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    struct Node* tail = head;

    while (tail->next != NULL) {
        tail = tail->next;
    }

    while (temp != NULL) {
        if (temp->child != NULL) {
            tail->next = temp->child;

            struct Node* childTail = temp->child;
            while (childTail->next != NULL) {
                childTail = childTail->next;
            }
            tail = childTail;
        }
        temp = temp->next;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = newNode(10);
    head->next = newNode(5);
    head->next->next = newNode(12);
    head->next->next->next = newNode(7);
    head->next->next->next->next = newNode(11);

    head->child = newNode(4);
    head->child->next = newNode(20);
    head->child->next->next = newNode(13);
    
    head->next->next->child = newNode(17);
    head->next->next->child->next = newNode(6);

    head->child->next->child = newNode(2);
    head->child->next->child->next = newNode(16);
    
    head->next->next->child->child = newNode(9);
    head->next->next->child->child->next = newNode(8);

    head->child->next->child->next->child = newNode(3);
    head->next->next->child->child->child = newNode(19);

    head->next->next->child->child->child->next = newNode(15);

    // Listeyi düzleştir
    Duzlestir(head);

    // Düzleştirilmiş listeyi yazdır
    printList(head);

    return 0;
}
