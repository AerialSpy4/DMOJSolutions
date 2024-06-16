#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+5;
int dp[MM][MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int d, ins, r;
    cin >> d >> ins >> r;
    string a, b;
    cin >> a >> b;
    // Get LCS
    int n = a.size(), m = b.size();
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=m; j++) {
            if (i == 0) {
                dp[i][j] = j*ins;
            } else if (j == 0) {
                dp[i][j] = i*d;
            } else if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j]+d, min(dp[i][j-1]+ins, dp[i-1][j-1]+r));
            }
        }
    }
    cout << dp[n][m] << "\n";
}