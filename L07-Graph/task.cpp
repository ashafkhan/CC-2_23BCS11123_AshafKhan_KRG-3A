#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<long long>> tasks(n, vector<long long>(2));

    for (int i = 0; i < n; i++) {
        cin >> tasks[i][0] >> tasks[i][1];
    }

    sort(tasks.begin(), tasks.end());

    long long time = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        time += tasks[i][0];
        ans += tasks[i][1] - time;
    }

    cout << ans;
}