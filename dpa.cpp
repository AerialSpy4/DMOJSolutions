#include <bits/stdc++.h>
using namespace std;
int arr[100005], dp[100005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    fill(dp, dp+n+2, 2e9);
    dp[0] = 0;
    for (int i=0; i<n; i++) {
        dp[i+1] = min(dp[i+1], dp[i]+abs(arr[i+1]-arr[i]));
        dp[i+2] = min(dp[i+2], dp[i]+abs(arr[i+2]-arr[i]));
    }
    cout << dp[n-1] << "\n";
}