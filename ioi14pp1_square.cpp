#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+5;
int N, dp[MM][MM], grid[MM][MM];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> grid[i][j];
            if (grid[i][j]) dp[i][j] = 1;
        }
    }
    int largestval = 0, cnt = 0;
    for (int i=N-1; i>=0; i--) {
        for (int j=N-1; j>=0; j--) {
            if (grid[i][j]) {
                dp[i][j] = min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1])) + 1;
            }
            if (dp[i][j] > largestval) {
                largestval = dp[i][j];
                cnt = 1;
            } else if (dp[i][j] == largestval) {
                cnt++;
            }
        }
    }
    cout << largestval * cnt << "\n";
}