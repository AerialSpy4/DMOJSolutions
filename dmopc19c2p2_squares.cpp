#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int MM = 505;
int arr[MM][MM], dp[MM][MM];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];

    for (int i=0; i<n; i++) {
        dp[i][0] = dp[i-1][0]+arr[i][0];
    }

    for (int i=0; i<m; i++) {
        dp[0][i] = dp[0][i-1]+arr[0][i];
    }

    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + arr[i][j];
        }
    }

    cout << dp[n-1][m-1] << endl;
}