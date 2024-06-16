#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int MM = 1e5+5;
int arr[MM], dp[MM];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    dp[1] = arr[1];
    dp[2] = arr[0]+arr[2];

    for (int i=3; i<n; i++) {
        dp[i] = max(dp[i-2], dp[i-3]) + arr[i];
    }

    cout << max(dp[n-1], dp[n-2]) << endl;
}