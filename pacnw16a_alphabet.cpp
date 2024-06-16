#include <bits/stdc++.h>
using namespace std;
const int MM = 55;
int dp[MM][MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 26 - LCS betwen abcd...z and string
    string s;
    cin >> s;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    int n = s.size();
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=26; j++) {
            if (s[i-1] == alpha[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << 26 - dp[n][26] << "\n";
}