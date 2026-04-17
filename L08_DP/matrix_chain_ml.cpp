// Matric Chain Multiplication
// TC: O(n^3)

#include <bits/stdc++.h>
using namespace std;

int mcm(vector<int> &arr, int i, int j, vector<vector<int>> &dp){
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;

    for(int k = i; k < j; k++){
        int steps = arr[i-1] * arr[k] * arr[j]
                  + mcm(arr, i, k, dp)
                  + mcm(arr, k+1, j, dp);

        ans = min(ans, steps);
    }

    return dp[i][j] = ans;
}

int main(){
    vector<int> arr = {10, 20, 30, 40};
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << mcm(arr, 1, n-1, dp) << "\n";
    return 0;
}