#include <iostream>
#include <vector>

using namespace std;

void dfsHelper(vector<vector<int>> &adj, vector<bool> &visited, int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfsHelper(adj, visited, neighbor);
    }
}

void dfs(vector<vector<int>> &adj, int start) {
    int V = adj.size();
    vector<bool> visited(V, false);
    dfsHelper(adj, visited, start);
}

int main() {
    vector<vector<int>> adj = {{1, 2}, {0, 3, 4}, {0, 4}, {1}, {1, 2}};
    cout << "DFS Traversal: ";
    dfs(adj, 0);
    return 0;
}
