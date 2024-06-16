#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int arr[200005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i=1; i<n; i++) {
        ans += max(0LL, arr[i-1]-arr[i]);
        if (arr[i] < arr[i-1]) {
            arr[i] = arr[i-1];
        }
    }
    cout << ans << endl;
}