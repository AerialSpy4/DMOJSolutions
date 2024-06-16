#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[105];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    double ans = 2e9;

    for (int i=1; i<n-1; i++) {
        ans = min(ans, (arr[i]-arr[i-1])/2.0 + (arr[i+1]-arr[i])/2.0);
    }

    cout << fixed << setprecision(1) << ans << endl;
}