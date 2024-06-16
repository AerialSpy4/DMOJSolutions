#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[105][100005];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, W;
    cin >> N >> W;
    for (int i=1; i<=N; i++) {
        int w, v;
        cin >> w >> v;
        for (int j=0; j<=W; j++) {
            if (j-w >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[N][W] << '\n';
}