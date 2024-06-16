#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
int density[MM][MM], dp[MM][MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l, d;
    cin >> l >> d;
    for (int i=1; i<=d; i++) {
        for (int j=1; j<=l; j++) {
            cin >> density[i][j];
        }
    }
    for (int i=0; i<MM; i++) {
        dp[i][0] = 2e9;
        dp[0][i] = 2e9;
    }
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = density[1][1];
    for (int t=0; t<4; t++) {
        for (int i=1; i<=d; i++) {
            for (int j=1; j<=l; j++) {
                if (i == 1 && j == 1) continue;
                if (j+1 <= l && dp[i][j+1] != 0) {
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i][j+1])) + density[i][j];
                } else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + density[i][j];
                }
            }
        }
    }
    int a, b;
    cin >> a >> b;
    cout << dp[b+1][a+1] << "\n";
}