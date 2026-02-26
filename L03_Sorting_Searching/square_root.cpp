#include<bits/stdc++.h>
using namespace std;

double eps = 1e-6; // 5 decimal places precision, basically epsilon is defined here to tell that how many decimal places we want accuracy in our answer

int main(){
    double x;
    cin>>x;
    
    double lo=1, hi=x, mid;
    while(hi - lo > eps){
        mid = lo + (hi-lo) / 2;
        if(mid * mid < x){
            lo = mid;
        }else{
            hi = mid;
        }
    }

    cout<< setprecision(10) << lo << "\n" << hi <<endl;
    // Verify using pow function (to find sqrt give argument as: pow(x, 1.0/2))
    cout<< pow(x, 1.0/2) <<endl;

    return 0;
}