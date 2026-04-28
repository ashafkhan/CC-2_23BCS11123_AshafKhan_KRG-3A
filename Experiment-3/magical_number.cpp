#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    const int MOD = 1e9 + 7;

    long long low = 1;
    long long high = (long long)n * min(a, b);
    long long L = lcm(a, b);

    while (low < high) {
        long long mid = low + (high - low) / 2;
        long long count = mid / a + mid / b - mid / L;

        if (count < n)
            low = mid + 1;
        else
            high = mid;
    }

    cout << low % MOD;
    return 0;
}
