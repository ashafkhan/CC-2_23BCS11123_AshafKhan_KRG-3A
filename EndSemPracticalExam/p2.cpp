#include <bits/stdc++.h>
using namespace std;

int tsp(int n, vector<vector<int>> &dist) {
    int N = 1 << n;
    vector<vector<int>> dp(N, vector<int>(n, INT_MAX));

    dp[1][0] = 0; // start from city 0

    for (int mask = 1; mask < N; mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            if (dp[mask][u] == INT_MAX) continue;

            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;

                int newMask = mask | (1 << v);
                dp[newMask][v] = min(dp[newMask][v],
                                     dp[mask][u] + dist[u][v]);
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        if (dp[N-1][i] != INT_MAX)
            ans = min(ans, dp[N-1][i] + dist[i][0]);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    cout << tsp(n, dist) << '\n';

    return 0;
}