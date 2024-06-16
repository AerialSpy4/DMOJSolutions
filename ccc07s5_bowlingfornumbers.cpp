#include <bits/stdc++.h>
using namespace std;
const int MM = 3e4+5;
int pins[MM], psa[MM], dp[505][MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N, K, W;
        cin >> N >> K >> W;
        for (int i=0; i<N; i++) {
            cin >> pins[i];
            psa[i+1]=psa[i]+pins[i];
        }
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=K; i++) { // Bowling Balls
            for (int j=1; j<=N; j++) { // Pins
                if (j < W) {
                    dp[i][j] = psa[i];
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j-W] + psa[j]-psa[j-W]);
                }
            }
        }
        cout << dp[K][N] << '\n';
    }
}