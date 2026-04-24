#include <bits/stdc++.h>
using namespace std;

vector<int> arr(1000);
vector<int> seg(4000);
vector<int> lazy(4000);

// Build segment tree
void build(int idx, int low, int high){
    if(low == high){
        seg[idx] = arr[low];
        return;
    }

    int mid = (low + high) / 2;

    build(2*idx + 1, low, mid);
    build(2*idx + 2, mid + 1, high);

    seg[idx] = max(seg[2*idx + 1], seg[2*idx + 2]);
}

// PUSH function (fixes applied)
void push(int idx, int low, int high){
    if(lazy[idx] != 0){
        seg[idx] += lazy[idx];

        if(low != high){
            lazy[2*idx + 1] += lazy[idx];
            lazy[2*idx + 2] += lazy[idx];
        }

        lazy[idx] = 0;  // IMPORTANT FIX
    }
}

// Range maximum query with lazy
int query(int idx, int low, int high, int l, int r){

    push(idx, low, high);  // IMPORTANT

    // No overlap
    if(high < l || low > r){
        return INT_MIN;
    }

    // Complete overlap
    if(low >= l && high <= r){
        return seg[idx];
    }

    int mid = (low + high) / 2;

    int left = query(2*idx + 1, low, mid, l, r);
    int right = query(2*idx + 2, mid + 1, high, l, r);

    return max(left, right);
}

// Range update (add val)
void updateRange(int idx, int low, int high, int l, int r, int val){

    push(idx, low, high);  // IMPORTANT

    // No overlap
    if(high < l || low > r)
        return;

    // Complete overlap
    if(low >= l && high <= r){
        lazy[idx] += val;
        push(idx, low, high);
        return;
    }

    int mid = (low + high) / 2;

    updateRange(2*idx + 1, low, mid, l, r, val);
    updateRange(2*idx + 2, mid + 1, high, l, r, val);

    // IMPORTANT: update current node
    seg[idx] = max(seg[2*idx + 1], seg[2*idx + 2]);
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    build(0, 0, n - 1);

    int q;
    cin >> q;

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n - 1, l, r) << "\n";
    }

    // Example update
    updateRange(0, 0, n - 1, 3, 5, 10);

    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n - 1, l, r) << "\n";
    }

    return 0;
}