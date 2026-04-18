#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX], visited[MAX];
int n;

// Function to create graph
void createGraph() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
}

// Display graph
void displayGraph() {
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

// DFS function
void DFS(int v) {
    int i;
    printf("%d ", v);
    visited[v] = 1;

    for(i = 0; i < n; i++) {
        if(adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

// BFS function
void BFS(int start) {
    int queue[MAX], front = -1, rear = -1;
    int i;

    queue[++rear] = start;
    visited[start] = 1;

    while(front != rear) {
        int v = queue[++front];
        printf("%d ", v);

        for(i = 0; i < n; i++) {
            if(adj[v][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

// Reset visited array
void resetVisited() {
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
    }
}

// Main menu
int main() {
    int choice, start;

    while(1) {
        printf("\n--- Graph Traversal Menu ---\n");
        printf("1. Create Graph\n");
        printf("2. Display Graph\n");
        printf("3. DFS Traversal\n");
        printf("4. BFS Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createGraph();
                break;

            case 2:
                displayGraph();
                break;

            case 3:
                resetVisited();
                printf("Enter starting vertex (0 to %d): ", n-1);
                scanf("%d", &start);
                printf("DFS Traversal: ");
                DFS(start);
                printf("\n");
                break;

            case 4:
                resetVisited();
                printf("Enter starting vertex (0 to %d): ", n-1);
                scanf("%d", &start);
                printf("BFS Traversal: ");
                BFS(start);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}