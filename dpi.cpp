#include <bits/stdc++.h>
using namespace std;
const int MM = 3005;
// DP[i][j]: probability first i coins get j heads
double arr[MM], dp[MM][MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        dp[i][0] = 1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            dp[i][j] = dp[i-1][j-1]*arr[i-1] + dp[i-1][j] * (1-arr[i-1]);
        }
    }
    cout << fixed << setprecision(9) << dp[n][n/2+1] << "\n";
}