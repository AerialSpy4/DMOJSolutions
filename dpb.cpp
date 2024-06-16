#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int arr[MM], dp[MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    fill(dp, dp+n, 2e9);
    dp[0] = 0;
    for (int i=0; i<n; i++) {
        for (int j=1; j<=k; j++) {
            dp[i+j] = min(dp[i+j], dp[i]+abs(arr[i+j]-arr[i]));
        }
    }
    cout << dp[n-1] << endl;
}