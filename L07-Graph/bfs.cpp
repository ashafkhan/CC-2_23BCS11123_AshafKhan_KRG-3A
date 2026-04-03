#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &G){
    int n = G.size();
    vector<int> vis(n, 0);
    queue<int> q;

    vector<int> ans;

    int src = 0;
    q.push(src);
    vis[src] = 1;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(auto nb : G[node]){
            if(!vis[nb]){
                vis[nb] = 1;
                q.push(nb);
            }

        }
    }

    // print nodes
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    vector<vector<int>> G = {{1}, {0,2,3}, {1, 4, 5}, {1,6}, {2}, {2}, {3,7}, {6}};
    bfs(G);

    return 0;
} 