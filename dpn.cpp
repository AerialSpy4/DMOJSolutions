#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 405;
int arr[MM], psa[MM];
// Min cost to get to [l, r] as a slime
int dp[MM][MM];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        psa[i+1] = psa[i] + arr[i];
    }
    for (int len=1; len<=n; len++) {
        for (int l=0; l<n-len+1; l++) {
            int r = l+len-1;
            if (l == r) {
                dp[l][r] = 0;
                continue;
            } else if (len == 2) {
                dp[l][r] = arr[l]+arr[r];
                continue;
            }
            dp[l][r] = 1e18;
            // split: before and inclusive (middle), after
            for (int s=l; s<=r-1; s++) {
                dp[l][r] = min(dp[l][r], dp[l][s]+dp[s+1][r]+psa[r+1]-psa[l]);
            }
        }
    }
    cout << dp[0][n-1] << "\n";
}