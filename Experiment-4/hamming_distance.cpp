#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long solve(vector<int> &A) {
    long long N = A.size();
    long long ans = 0;

    for (int bit = 0; bit < 31; bit++) {
        long long count1 = 0;

        for (int i = 0; i < N; i++) {
            if (A[i] & (1LL << bit)) {
                count1++;
            }
        }

        long long count0 = N - count1;

        long long contribution = (2LL * count1 % MOD * count0 % MOD) % MOD;
        ans = (ans + contribution) % MOD;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        cout << solve(A) << "\n";
    }

    return 0;
}
