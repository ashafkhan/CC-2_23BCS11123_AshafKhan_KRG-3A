#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &G, vector<int> & vis, vector<int> ans, int src){
    ans.push_back(src);
    

}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    vector<vector<int>> G = {{1}, {0,2,3}, {1, 4, 5}, {1,6}, {2}, {2}, {3,7}, {6}};
    int n = G.size();

    vector<int> vis(n);
    vector<int> ans(n);
    int src = 0;
    dfs(G, vis, ans, src);

    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<"\n";

    return 0;
} 