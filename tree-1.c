#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 8 // Maksimum deüğüm sayısı, 1 tabanlı indeksleme için  +1

// Ağaçtaki bir düğümü temsil eden yapı
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Yeni bir düğüm oluşturma işlevi
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// x ve y köşeleri arasına bir kenar ekleme fonksiyonu
void addEdge(int x, int y, struct Node *adj[])
{
    struct Node *newNode = createNode(y);
    newNode->next = adj[x];
    adj[x] = newNode;

    newNode = createNode(x);
    newNode->next = adj[y];
    adj[y] = newNode;
}

// Her düğümün ebeveynini yazdıran fonksiyon
void printParents(int node, struct Node *adj[], int parent)
{
    if (parent == 0)
    {
        printf("%d->Root\n", node);
    }
    else
    {
        printf("%d->%d\n", node, parent);
    }

    struct Node *current = adj[node];
    while (current != NULL)
    {
        if (current->data != parent)
        {
            printParents(current->data, adj, node);
        }
        current = current->next;
    }
}

// Her düğümün çocuklarını yazdıran fonksiyon
void printChildren(int Root, struct Node *adj[])
{
    int visited[MAX_NODES] = {0};
    struct Node *queue[MAX_NODES];
    int front = -1, rear = -1;

    queue[++rear] = adj[Root];
    visited[Root] = 1;

    while (front != rear)
    {
        struct Node *current = queue[++front];
        printf("%d-> ", front);
        while (current != NULL)
        {
            if (!visited[current->data])
            {
                printf("%d ", current->data);
                queue[++rear] = adj[current->data];
                visited[current->data] = 1;
            }
            current = current->next;
        }
        printf("\n");
    }
}

// Yaprak düğümleri yazdırma fonksiyonu
void printLeafNodes(int Root, struct Node *adj[])
{
    for (int i = 1; i <= MAX_NODES; i++)
    {
        struct Node *current = adj[i];
        int count = 0;
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
        if (count == 1 && i != Root)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Her düğümün derecesini yazdıran fonksiyon
void printDegrees(int Root, struct Node *adj[])
{
    for (int i = 1; i <= MAX_NODES; i++)
    {
        struct Node *current = adj[i];
        int count = 0;
        while (current != NULL)
        {
            count++;
            current = current->next;
        }
        if (i == Root)
        {
            printf("%d: %d\n", i, count);
        }
        else
        {
            printf("%d: %d\n", i, count - 1);
        }
    }
}

int main()
{
  

    int N = 7, Root = 1;                  // Düğüm sayısı
    struct Node *adj[MAX_NODES] = {NULL}; // Ağacın saklanacağı bitişiklik
    addEdge(1, 2, adj);                   // Ağaç oluşturuluyor
    addEdge(1, 3, adj);
    addEdge(1, 4, adj);
    addEdge(2, 5, adj);
    addEdge(2, 6, adj);
    addEdge(4, 7, adj);
    printf("Her bir dugumun ebeveynleri:\n");
    printParents(Root, adj, 0);

    printf("Her bir dugumun cocucklari:\n");
    printChildren(Root, adj);

    printf("Agacin yaprak dugumleri:\n");
    printLeafNodes(Root, adj);

    printf("Her bir dugumun dereceleri:\n");
    printDegrees(Root, adj);
    return 0;
}