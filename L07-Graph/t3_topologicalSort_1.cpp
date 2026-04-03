// stack + DFS => DFS topo
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for (int nei : adj[node]) {
            if (!vis[nei]) dfs(nei, adj, vis, st);
        }
        st.push(node);
    }

    vector<int> topoSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs(i, adj, vis, st);
        }

        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }

        return topo;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution obj;
    vector<int> ans = obj.topoSort(adj);

    for (int x : ans) cout << x << " ";
}