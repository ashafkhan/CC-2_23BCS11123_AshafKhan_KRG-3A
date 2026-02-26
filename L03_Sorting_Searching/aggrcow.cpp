#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n , cows;
int positions[N];

bool canPlaceCows(int minDist){
    int lastPos = -1;
    int cows_cnt = cows;
    for(int i=0; i<n; i++){
        if(positions[i] - lastPos >= minDist || lastPos == -1){
            lastPos = positions[i];
            cows_cnt--;
            if(cows_cnt == 0){
                break;
            }
        }
    }

    return cows_cnt == 0;
}

void aggrCows(){
    int lo=0, hi=1e9;
    while(hi - lo > 1){
        int mid = lo + (hi-lo)/2;
        if(canPlaceCows(mid)){
            lo = mid;
        }else{
            hi = mid-1;
        }
    }
    if(canPlaceCows(hi)){
        cout<<hi<<"\n";
    }else if(canPlaceCows(lo)){
        cout<<lo<<"\n";
    }else{
        cout<<-1<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        cin>>n>>cows;
        for(int i=0; i<n; i++){
            cin>>positions[i];
        }
        sort(positions, positions+n);
        aggrCows();
    }

    return 0;
}

// TC: nlogn + log(10^9) * n