// Kosaraju’s Algorithm (SCC)

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st) {
    vis[node] = true;
    for (int nei : adj[node]) {
        if (!vis[nei]) dfs(nei, adj, vis, st);
    }
    st.push(node);
}

void dfs2(int node, vector<vector<int>>& adjT, vector<bool>& vis) {
    vis[node] = true;
    cout << node << " ";
    for (int nei : adjT[node]) {
        if (!vis[nei]) dfs2(nei, adjT, vis);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V), adjT(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }

    vector<bool> vis(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) dfs(i, adj, vis, st);
    }

    fill(vis.begin(), vis.end(), false);

    cout << "Strongly Connected Components:\n";

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!vis[node]) {
            dfs2(node, adjT, vis);
            cout << "\n";
        }
    }
}