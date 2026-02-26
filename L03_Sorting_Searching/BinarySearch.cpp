#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> & v, int n, int target){
    int lo = 0, hi = n-1;
    while(hi - lo > 1){
        int mid = lo + (hi - lo) / 2;
        if(v[mid] < target){
            lo = mid+1;
        }else{
            hi = mid;
        }
    }

    if(v[lo] == target){
        cout<<lo<<"\n";
    }else if(v[hi] == target){
        cout<<hi<<"\n";
    }else{
        cout<<-1<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int target;
    cin>>target;
    solve(v, n, target);

    return 0;
}