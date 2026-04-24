#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<pair<int,int>>& arr, int l, int mid, int r, vector<int>& count) {
        vector<pair<int,int>> temp;
        int i = l, j = mid + 1;

        while (i <= mid && j <= r) {
            if (arr[i].first > arr[j].first) {
                count[arr[i].second] += (r - j + 1);
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }

        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= r) temp.push_back(arr[j++]);

        for (int k = l; k <= r; k++) {
            arr[k] = temp[k - l];
        }
    }

    void mergeSort(vector<pair<int,int>>& arr, int l, int r, vector<int>& count) {
        if (l >= r) return;

        int mid = (l + r) / 2;
        mergeSort(arr, l, mid, count);
        mergeSort(arr, mid + 1, r, count);
        merge(arr, l, mid, r, count);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        vector<pair<int,int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1, count);
        return count;
    }
};

int main() {
    Solution obj;

    // Example input
    vector<int> nums = {5, 2, 6, 1};

    vector<int> result = obj.countSmaller(nums);

    // Output
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}