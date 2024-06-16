#include <bits/stdc++.h>
using namespace std;
// dp stores maximum difference in range [i, j] (if both guys play perfectly)
int arr[1005], dp[1005][1005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, total = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        dp[i][i] = arr[i];
        total += arr[i];
    }
    for (int l=2; l<=n; l++) {
        for (int i=0; i+l-1<n; i++) {
            int j = i+l-1;
            dp[i][j] = max(arr[i]-dp[i+1][j], arr[j]-dp[i][j-1]);
        }
    }
    cout << (total + dp[0][n-1]) / 2 << "\n";
}