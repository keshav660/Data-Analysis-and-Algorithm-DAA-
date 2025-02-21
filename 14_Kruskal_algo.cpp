#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int v, vector<int> &parent) {
    if (v == parent[v]) return v;
    return parent[v] = findParent(parent[v], parent);
}

void kruskal(vector<Edge> &edges, int V) {
    sort(edges.begin(), edges.end(), compare);
    vector<int> parent(V);
    for (int i = 0; i < V; i++) parent[i] = i;

    int mstCost = 0;
    for (auto &edge : edges) {
        int pu = findParent(edge.u, parent);
        int pv = findParent(edge.v, parent);

        if (pu != pv) {
            parent[pu] = pv;
            mstCost += edge.weight;
            cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
        }
    }
    cout << "Total MST Cost: " << mstCost << endl;
}

int main() {
    vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    cout << "Kruskal's MST:\n";
    kruskal(edges, 4);
    return 0;
}
