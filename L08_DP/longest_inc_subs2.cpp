// Longest Increasing Subsequence (LIS) using binary search
// TC: O(nlogn)

#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> arr){
    int n = arr.size();

    vector<int> ans;
    ans.push_back(arr[0]);

    for(int i = 1; i < n; i++){
        if(ans.back() < arr[i]){
            ans.push_back(arr[i]);
        }else{
            int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[idx] = arr[i];
        }
    }

    return ans.size();
}

int main(){
    vector<int> arr = {1, 3, 7, 2, 5};

    cout << LIS(arr) <<"\n";

    return 0;
}