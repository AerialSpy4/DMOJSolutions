#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+5;
int n, m, a[MM], b[MM], dp[MM][MM];
void solve() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<m; i++) {
        cin >> b[i];
    }
    for (int i=1 ; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << "\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}