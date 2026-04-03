#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &G){
    int n = G.size();
    vector<int> vis(n, 0);
    queue<int> q;

    vector<int> rep;

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            rep.push_back(i);

            q.push(i);
            vis[i] = 1;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto nb : G[node]){
                    if(!vis[nb]){
                        vis[nb] = 1;
                        q.push(nb);
                    }
                }
            }
        }
    }

    cout << rep.size() - 1 << "\n";

    // for(int i = 1; i < rep.size(); i++){
    //     cout << rep[i-1] << " " << rep[i] << "\n";
    // }
    for(auto it : rep){
        cout<< it << " ";
    }
    cout<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> G = {
        {1}, {0}, {3}, {2}
    };

    bfs(G);

    return 0;
}