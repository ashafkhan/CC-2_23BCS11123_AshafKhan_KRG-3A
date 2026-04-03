// Topological Sort (Kahn + DFS)

#include <bits/stdc++.h>
using namespace std;

vector<int> kahnsAlgorithm(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++) {
        for (int nei : adj[i]) {
            indegree[nei]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> topo;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int nei : adj[node]) {
            indegree[nei]--;
            if (indegree[nei] == 0) q.push(nei);
        }
    }

    if ((int)topo.size() != V) return {};
    return topo;
}

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
    vis[node] = true;
    for (int nei : adj[node]) {
        if (!vis[nei]) dfs(nei, adj, vis, st);
    }
    st.push(node);
}

vector<int> dfsTopoSort(int V, vector<vector<int>>& adj) {
    vector<bool> vis(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) dfs(i, adj, vis, st);
    }

    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << "Kahn's Algorithm (BFS Topological Sort):\n";
    vector<int> kahn = kahnsAlgorithm(V, adj);

    if (kahn.empty()) {
        cout << "Cycle detected, no topological order possible.\n";
    } else {
        for (int x : kahn) cout << x << " ";
        cout << "\n";
    }

    cout << "DFS Topological Sort:\n";
    vector<int> dfsTopo = dfsTopoSort(V, adj);

    for (int x : dfsTopo) cout << x << " ";
    cout << "\n";
}