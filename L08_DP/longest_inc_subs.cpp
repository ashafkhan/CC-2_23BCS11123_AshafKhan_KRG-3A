// Longest Increasing Subsequence (LIS) using DP
// TC: O(n^2)

#include <bits/stdc++.h>
using namespace std;

int LIS(int curr, int prev, vector<int>& arr, vector<vector<int>>& dp) {
    if (curr == arr.size())
        return 0;

    if(dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

    int notPick = LIS(curr + 1, prev, arr, dp);

    int pick = 0;
    if (prev == -1 || arr[curr] > arr[prev]) {
        pick = 1 + LIS(curr + 1, curr, arr, dp);
    }

    return dp[curr][prev + 1] = max(pick, notPick);
}

int main() {
    vector<int> arr = {1, 3, 7, 2, 5};
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    cout << LIS(0, -1, arr, dp) <<"\n";

    return 0;
}