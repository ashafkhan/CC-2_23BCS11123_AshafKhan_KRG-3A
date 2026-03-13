#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;

    for (int num : nums) {
        ones = (ones ^ num) & ~twos;
        twos = (twos ^ num) & ~ones;
    }

    return ones;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = singleNumber(nums);

    cout << result << endl;

    return 0;
}