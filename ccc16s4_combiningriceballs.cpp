#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 405;
int arr[MM], dp[MM][MM];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for (int len=1; len<=n; len++) {
        for (int l=0; l<n-len+1; l++) {
            int r = l+len-1;
            if (l == r) {
                dp[l][r] = arr[l];
                continue;
            }
            // split: before and inclusive (middle), after -> 2 elements
            for (int s=l; s<=r-1; s++) {
                if (dp[l][s] == dp[s+1][r] && dp[l][s] != 0) {
                    dp[l][r] = max(dp[l][r], dp[l][s]+dp[s+1][r]); 
                }
            }
            // split: three sections -> 3 elements
            for (int s1=l; s1<=r-2; s1++) {
                for (int s2=s1+1; s2<=r-1; s2++) {
                    if (dp[l][s1] == dp[s2+1][r] && dp[l][s1] != 0 && dp[s1+1][s2] != 0) {
                        dp[l][r] = max(dp[l][r], dp[l][s1] + dp[s1+1][s2] + dp[s2+1][r]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}