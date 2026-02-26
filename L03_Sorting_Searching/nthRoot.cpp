// Nth root of a number using Binary Search

/*
    N - N+1 : 10^d numbers
    1 - N : N * 10^d numbers
    TC: p * log (N * 10^d)
    for pth root of number N
    with d decimal accuracy

    Note: this code has some issue, as it fails to return cube root of 27 by returning "lo", but successfully calc returning "hi"
*/


#include<bits/stdc++.h>
using namespace std;

double eps = 1e-6; // 5 decimal places precision

double multiply(double mid, int n){
    double ans = 1;
    for(int i=0; i<n; i++){
        ans *= mid;
    }
    return ans;
}

int main(){
    double x;
    cin>>x;
    int n; // n as input for nth root
    cin>>n;
    double lo=1, hi=x, mid;
    while(hi - lo > eps){
        mid = lo + (hi-lo) / 2;
        if(multiply(mid, n) < x){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    
    cout<< setprecision(10) << lo << "\n" << hi <<endl;
    // Verify using pow function (to find nth root give argument as: pow(x, 1.0/n))
    cout<< pow(x, 1.0/n) <<endl;

    return 0;
}