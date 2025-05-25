#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int findMinVertex(vector<int> &key, vector<bool> &inMST, int V) {
    int minIndex = -1, minValue = INF;
    for (int i = 0; i < V; i++) {
        if (!inMST[i] && key[i] < minValue) {
            minValue = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void primMST(vector<vector<int>> &graph, int V) {
    vector<int> parent(V, -1); // Stores MST edges
    vector<int> key(V, INF);   // Stores min edge weight
    vector<bool> inMST(V, false); // Track included nodes

    key[0] = 0; // Start from node 0

    for (int i = 0; i < V - 1; i++) {
        int u = findMinVertex(key, inMST, V);
        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Prim's MST:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    int V = graph.size();
    primMST(graph, V);
    return 0;
}
