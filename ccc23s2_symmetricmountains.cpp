#include <bits/stdc++.h>
using namespace std;
const int MM = 5005;
int arr[MM], dp[MM][MM], mv[MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    fill(mv, mv+n+1, 2e9);
    for (int l=1; l<=n; l++) {
        for (int i=0; i+l-1<n; i++) {
            int j = i+l-1;
            if (i == j) {
                dp[i][j] = 0;
            } else if (j-i == 1) {
                dp[i][j] = abs(arr[i]-arr[j]);
                mv[j-i+1] = min(mv[j-i+1], dp[i][j]);
            } else {
                dp[i][j] = dp[i+1][j-1] + abs(arr[i]-arr[j]);
                mv[j-i+1] = min(mv[j-i+1], dp[i][j]);
            }
        }
    }
    mv[1] = 0;
    for (int i=1; i<=n; i++) {
        cout << mv[i] << " ";
    }
}