#include <bits/stdc++.h>
using namespace std;

// DSU
vector<int> parent, sizeArr;
int numComponents, maxComponentSize;

int findUPar(int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findUPar(parent[node]); // path compression
}

void unionBySize(int u, int v) {
    int pu = findUPar(u);
    int pv = findUPar(v);

    if (pu == pv) return;

    if (sizeArr[pu] < sizeArr[pv]) {
        parent[pu] = pv;
        sizeArr[pv] += sizeArr[pu];
        maxComponentSize = max(maxComponentSize, sizeArr[pv]);
    } else {
        parent[pv] = pu;
        sizeArr[pu] += sizeArr[pv];
        maxComponentSize = max(maxComponentSize, sizeArr[pu]);
    }

    numComponents--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n)) return 0;
    cin >> m;

    parent.resize(n + 1);
    sizeArr.resize(n + 1, 1);

    numComponents = n;
    maxComponentSize = 1;

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    string output = "";

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        unionBySize(u, v);

        output += to_string(numComponents) + " " + to_string(maxComponentSize) + "\n";
    }

    cout << output;

    return 0;
}