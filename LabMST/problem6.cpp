#include <bits/stdc++.h>
using namespace std;

int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());

    int left = 0;
    int right = tokens.size() - 1;
    int score = 0;
    int maxScore = 0;

    while (left <= right) {

        if (power >= tokens[left]) {
            power -= tokens[left];
            score++;
            left++;
            maxScore = max(maxScore, score);
        }

        else if (score > 0) {
            power += tokens[right];
            score--;
            right--;
        }
        else {
            break;
        }
    }

    return maxScore;
}

int main() {
    int n;
    cout << "Enter number of tokens: ";
    cin >> n;

    vector<int> tokens(n);

    cout << "Enter token values:\n";
    for (int i = 0; i < n; i++) {
        cin >> tokens[i];
    }

    int power;
    cout << "Enter initial power: ";
    cin >> power;

    int result = bagOfTokensScore(tokens, power);

    cout << "Maximum Score: " << result << endl;

    return 0;
}