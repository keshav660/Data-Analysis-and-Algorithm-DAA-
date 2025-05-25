#include <stdio.h>
#define SIZE 100

int queue[SIZE], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == SIZE - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

void BFS(int graph[10][10], int n, int start) {
    int visited[10] = {0};
    enqueue(start);
    visited[start] = 1;
    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        for (int i = 0; i < n; i++) {
            if (graph[node][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int graph[10][10] = {
        {0,1,1,0},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,0}
    };
    BFS(graph, 4, 0);
    return 0;
}
