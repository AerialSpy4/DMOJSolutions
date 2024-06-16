#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[100005];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, W;
    cin >> N >> W;
    for (int i=1; i<=N; i++) {
        int w, v;
        cin >> w >> v;
        for (int j=W; j>=w; j--) {
            dp[j] = max(dp[j], dp[j-w]+v);
        }
    }
    cout << dp[W] << '\n';
}