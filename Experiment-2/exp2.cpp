#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) return n;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        map<pair<int,int>, int> mp;
        int currMax = 0;

        for (int j = i + 1; j < n; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            if (dx == 0) {
                dy = 1;  // vertical line
            } else if (dy == 0) {
                dx = 1;  // horizontal line
            } else {
                int g = __gcd(abs(dx), abs(dy));
                dx /= g;
                dy /= g;

                // Normalize sign
                if (dx < 0) {
                    dx *= -1;
                    dy *= -1;
                }
            }

            mp[{dy, dx}]++;
            currMax = max(currMax, mp[{dy, dx}]);
        }

        ans = max(ans, currMax + 1); // +1 for anchor point
    }

    return ans;
}

int main() {
    vector<vector<int>> points = {{1,1}, {2,2}, {3,3}};
    cout << maxPoints(points) << endl;
    return 0;
}