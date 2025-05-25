#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX

void floydWarshall(vector<vector<int>> &graph, int V) {
    vector<vector<int>> dist = graph;

    for (int k = 0; k < V; k++) { 
        for (int i = 0; i < V; i++) { 
            for (int j = 0; j < V; j++) { 
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    cout << "Floyd-Warshall Distance Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 3, INF, INF},
        {2, 0, INF, INF},
        {INF, 7, 0, 1},
        {6, INF, INF, 0}};

    int V = graph.size();
    floydWarshall(graph, V);
    return 0;
}
