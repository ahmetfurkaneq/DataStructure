#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int graph[10][3] = {
    {1, 4, 5}, {0, 2, 6}, {1, 3, 7},
    {2, 4, 8}, {0, 3, 9}, {0, 7, 8},
    {1, 8, 9}, {2, 5, 9}, {3, 5, 6},
    {4, 6, 7}
};
char vertices[10] = {'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E'};

int findWalk(char* sequence, int index, int lastVertex, int* path, int pathIndex) {
    if (index == strlen(sequence)) {
        int i;
        for (i = 0; i < pathIndex; i++) {
            printf("%d", path[i]);
        }
        printf("\n");
        return 1;
    }

    int i;
    for (i = 0; i < 3; i++) {
        int nextVertex = graph[lastVertex][i];
        if (vertices[nextVertex] == sequence[index]) {
            path[pathIndex] = nextVertex;
            if (findWalk(sequence, index + 1, nextVertex, path, pathIndex + 1))
                return 1;
        }
    }
    return 0;
}

int main() {
    char sequence[100];
    int path[100];
    int i;

    printf("Lütfen bir harf dizisi girin (Örneğin: aaddccee): ");
    scanf("%s", sequence);

   
    for (i = 0; sequence[i]; i++) {
        sequence[i] = toupper(sequence[i]);
    }

    for (i = 0; i < 10; i++) {
        if (vertices[i] == sequence[0]) {
            path[0] = i;
            if (findWalk(sequence, 1, i, path, 1))
                return 0;
        }
    }

    printf("-1\n"); 
}