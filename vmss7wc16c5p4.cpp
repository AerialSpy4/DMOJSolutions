#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int MM = 1e5+5;
int dp[MM];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int x, y, z;
    cin >> x >> y >> z;

    dp[x] = 1;
    dp[y] = 1;
    dp[z] = 1;

    // CCC golf but you need the most putts ??

    for (int i=1; i<=n; i++) {
        if (i-x >= 0 && dp[i-x] != 0) dp[i] = max(dp[i], dp[i-x]+1);
        if (i-y >= 0 && dp[i-y] != 0) dp[i] = max(dp[i], dp[i-y]+1);
        if (i-z >= 0 && dp[i-z] != 0) dp[i] = max(dp[i], dp[i-z]+1);
    }

    cout << dp[n] << endl;
}