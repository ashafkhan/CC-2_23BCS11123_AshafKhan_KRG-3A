#include <bits/stdc++.h>
using namespace std;
vector<int> buildLPS(string pat) {
    int m = pat.length();
    vector<int> lps(m, 0);

    int len = 0;  
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void KMPSearch(string txt, string pat) {
    int n = txt.length();
    int m = pat.length();

    if (m == 0) return;   

    vector<int> lps = buildLPS(pat);

    int i = 0;  
    int j = 0;  

    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && txt[i] != pat[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string txt = "ababcababd";
    string pat = "ababd";

    KMPSearch(txt, pat);

    return 0;
}