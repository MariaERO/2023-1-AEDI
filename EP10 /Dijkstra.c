#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int city;
    int time;
} Node;

#define MAX_CITIES 1001
#define INF 999999 // large enough number to represent an 'infinite' int for cities without direct routes

// modified Breadth First Search algorithm
int bfs(int **graph, int N, int C, int R, int E) {
    int *visited = (int *)calloc(N + 1, sizeof(int)); // keeps track of visited cities
    Node *queue = (Node *)malloc(N * sizeof(Node)); // queue to optimize time, instead of using recursive functions to perform the traversal

    int front = 0, rear = 0;
    queue[rear].city = C;
    queue[rear].time = 0;
    rear++; // running through cities

    visited[C] = 1;

    while (front < rear) {
        Node current = queue[front];
        front++;

        int city = current.city;
        int time = current.time;

        if (city == R) {
            free(visited);
            free(queue);
            return time;
        }
    // while queue not empty, keep exploring cities and performing dequeue

    // for each not prohibited city, with a direct route and not visited yet: marks as visited and runs queue
        for (int i = 1; i <= N; i++) {
            if (i != E && graph[city][i] != INF && !visited[i]) { // Avoiding city E
                visited[i] = 1;
                queue[rear].city = i;
                queue[rear].time = time + 1;
                rear++;
            }
        }
    }

    free(visited);
    free(queue);
    return -1; // No path found
}

int main() {
    int N, M;

    while (scanf("%d %d", &N, &M) != EOF) {
        int **graph = (int **)malloc((N + 1) * sizeof(int *));
        for (int i = 0; i <= N; i++) {
            graph[i] = (int *)malloc((N + 1) * sizeof(int));
            for (int j = 0; j <= N; j++) {
                if (i == j) {
                    graph[i][j] = 0;
                } else {
                    graph[i][j] = INF;
                }
            }
        }

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            graph[A][B] = graph[B][A] = 1;
        }

        int C, R, E;
        scanf("%d %d %d", &C, &R, &E);

        int time = bfs(graph, N, C, R, E);
        printf("%d\n", time);

        for (int i = 0; i <= N; i++) {
            free(graph[i]);
        }
        free(graph);
    }

    return 0;
}
