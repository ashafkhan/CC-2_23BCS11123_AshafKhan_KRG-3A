#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long seg[4*N], lazy[4*N];

// Build
void build(int idx, int low, int high, vector<int> &arr) {
    if (low == high) {
        seg[idx] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2*idx+1, low, mid, arr);
    build(2*idx+2, mid+1, high, arr);
    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

// Lazy Propagation
void propagate(int idx, int low, int high) {
    if (lazy[idx] != 0) {
        seg[idx] += (high - low + 1) * lazy[idx];

        if (low != high) {
            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];
        }

        lazy[idx] = 0;
    }
}

// Range Update (Type 2)
void update(int idx, int low, int high, int l, int r, int val) {
    propagate(idx, low, high);

    if (high < l || low > r) return;

    if (low >= l && high <= r) {
        lazy[idx] += val;
        propagate(idx, low, high);
        return;
    }

    int mid = (low + high) / 2;
    update(2*idx+1, low, mid, l, r, val);
    update(2*idx+2, mid+1, high, l, r, val);

    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
}

// Range Sum Query (Type 1)
long long query(int idx, int low, int high, int l, int r) {
    propagate(idx, low, high);

    if (high < l || low > r) return 0;

    if (low >= l && high <= r) return seg[idx];

    int mid = (low + high) / 2;
    return query(2*idx+1, low, mid, l, r) +
           query(2*idx+2, mid+1, high, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    build(0, 0, n-1, arr);

    int q; 
    cin >> q;

    while (q--) {
        int type; 
        cin >> type;

        if (type == 1) {
            int l, r; 
            cin >> l >> r;
            cout << query(0, 0, n-1, l, r) << '\n';
        } 
        else if (type == 2) {
            int l, r, val; 
            cin >> l >> r >> val;
            update(0, 0, n-1, l, r, val);
        }
    }

    return 0;
}