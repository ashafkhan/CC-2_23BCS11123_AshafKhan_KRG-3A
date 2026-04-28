#include <bits/stdc++.h>
using namespace std;

// Compute C(n, k) % 10 using iterative method
int nCr_mod10(int n, int r) {
    if (r > n) return 0;
    if (r > n - r) r = n - r;

    long long res = 1;
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res /= (i + 1);
        res %= 10;  // keep mod 10
    }
    return res % 10;
}

int triangularSum(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int coeff = nCr_mod10(n - 1, i);
        ans = (ans + nums[i] * coeff) % 10;
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << triangularSum(nums) << endl;  // Output: 8
    return 0;
}