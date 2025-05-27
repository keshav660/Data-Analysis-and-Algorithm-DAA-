#include <iostream>
using namespace std;

#define MAX 100

// BFS function
void bfs(int adj[MAX][MAX], int V, int start) {
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    cout << "BFS Traversal: ";
    while (front < rear) {
        int node = queue[front++];
        cout << node << " ";

        for (int i = 0; i < V; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    cout << endl;
}

// DFS helper function (recursive)
void dfsHelper(int adj[MAX][MAX], int visited[MAX], int V, int node) {
    visited[node] = 1;
    cout << node << " ";
    for (int i = 0; i < V; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfsHelper(adj, visited, V, i);
        }
    }
}

// DFS function
void dfs(int adj[MAX][MAX], int V, int start) {
    int visited[MAX] = {0};
    cout << "DFS Traversal: ";
    dfsHelper(adj, visited, V, start);
    cout << endl;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int adj[MAX][MAX];

    cout << "Enter adjacency matrix (0/1):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> adj[i][j];

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    bfs(adj, V, start);
    dfs(adj, V, start);

    return 0;
}
