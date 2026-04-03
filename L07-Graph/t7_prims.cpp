#include <bits/stdc++.h>
using namespace std;

struct Pair {
    int node;
    int weight;
};

void prims(int V, vector<vector<Pair>>& adj) {
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);
    vector<int> parent(V, -1);

    // Min heap (weight, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push({0, 0}); // {weight, node}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (mstSet[u]) continue;
        mstSet[u] = true;

        for (auto p : adj[u]) {
            int v = p.node;
            int weight = p.weight;

            if (!mstSet[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    // Print MST edges
    cout << "MST edges:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " : " << key[i] << "\n";
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<Pair>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    prims(V, adj);

    return 0;
}