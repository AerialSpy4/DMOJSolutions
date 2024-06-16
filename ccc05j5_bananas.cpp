#include <bits/stdc++.h>
using namespace std;
const int MM = 55;
bool dp[MM][MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        string s;
        cin >> s;
        int n = s.size();
        if (s == "X") break;
        memset(dp, false, sizeof(dp));
        for (int len=1; len<=n; len++) {
            for (int l=0; l+len-1<n; l++) {
                int r = l+len-1;
                if (len == 1) {
                    if (s[l] == 'A') dp[l][r] = true;
                } else if (dp[l+1][r-1] && s[l] == 'B' && s[r] == 'S') {
                    dp[l][r] = true;
                } else {
                    for (int sp=l+1; sp<=r-1; sp++) {
                        if (dp[l][sp-1] && s[sp] == 'N' && dp[sp+1][r]) {
                            dp[l][r] = true;
                            break;
                        }
                    }
                }
            }
        }
        if (dp[0][n-1]) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}