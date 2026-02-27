#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> mp;
    string team;

    for(int i = 0; i < n; i++) {
        cin >> team;
        mp[team]++;
    }

    string winner;
    int maxGoals = 0;

    for(auto &p : mp) {
        if(p.second > maxGoals) {
            maxGoals = p.second;
            winner = p.first;
        }
    }

    cout << winner << endl;

    return 0;
}