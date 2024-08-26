#include <stdlib.h>
#include <stdio.h>

typedef struct n {
    int x;
    struct n *next;
} node;

int main() {
    node *check = NULL; // Initialize check pointer
    node *root = NULL;  // Initialize root pointer

    root = (node *)malloc(sizeof(node));
    root->x = 25;
    root->next = (node *)malloc(sizeof(node));
    root->next->x = 10;
    root->next->next = (node *)malloc(sizeof(node));
    root->next->next->x = 15;
    root->next->next->next = (node *)malloc(sizeof(node));
    root->next->next->next->x = 255;
    root->next->next->next->next = NULL; 

    check = root;

    while (check != NULL) {
        printf("%d ", check->x); 
        check = check->next;     
    }
    
    // Free dynamically allocated memory
    while (root != NULL) {
        node *temp = root->next;
        free(root);
        root = temp;
    }

    return 0;
}
