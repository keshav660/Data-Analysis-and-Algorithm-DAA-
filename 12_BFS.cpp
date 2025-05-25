#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &adj, int start) {
    int V = adj.size();
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    vector<vector<int>> adj = {{1, 2}, {0, 3, 4}, {0, 4}, {1}, {1, 2}};
    cout << "BFS Traversal: ";
    bfs(adj, 0);
    return 0;
}
