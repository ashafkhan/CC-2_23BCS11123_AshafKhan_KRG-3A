#include <bits/stdc++.h>
using namespace std;

// DSU (Disjoint Set)
vector<int> parent, rankArr;

int findUPar(int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findUPar(parent[node]); // path compression
}

void unionSet(int u, int v) {
    int pu = findUPar(u);
    int pv = findUPar(v);

    if (pu == pv) return;

    if (rankArr[pu] < rankArr[pv]) {
        parent[pu] = pv;
    } else if (rankArr[pu] > rankArr[pv]) {
        parent[pv] = pu;
    } else {
        parent[pv] = pu;
        rankArr[pu]++;
    }
}

// Kruskal Function
int kruskalsMST(int V, vector<vector<int>>& edges) {
    // Sort edges based on weight
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
        return a[2] < b[2];
    });

    parent.resize(V);
    rankArr.resize(V, 1);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int cost = 0, count = 0;

    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];

        if (findUPar(u) != findUPar(v)) {
            unionSet(u, v);
            cost += w;
            count++;

            if (count == V - 1) break;
        }
    }

    return cost;
}

int main() {
    int V = 4;

    vector<vector<int>> edges = {
        {0, 1, 10},
        {1, 3, 15},
        {2, 3, 4},
        {2, 0, 6},
        {0, 3, 5}
    };

    cout << kruskalsMST(V, edges) << endl;

    return 0;
}