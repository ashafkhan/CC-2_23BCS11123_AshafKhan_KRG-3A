#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n;
long long m;
long long trees[N];

bool isWoodSufficient(int h){
    long long wood = 0;
    for(int i=0; i<n; i++){
        if(trees[i] > h){
            wood += (trees[i] - h);
        }
    }
    return wood >= m;
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>trees[i];
    }

    long long lo=0, hi=1e9;
    while(hi - lo > 1){
        int mid = lo + (hi - lo) / 2;
        if(isWoodSufficient(mid)){
            lo = mid;
        }else{
            hi = mid-1;
        }
    }

    if(isWoodSufficient(hi)){
        cout<<hi<<"\n";
    }else if(isWoodSufficient(lo)){
        cout<<lo<<"\n";
    }else{
        cout<<-1<<"\n";
    }
}

// TC : O(NlogH) - nlogn