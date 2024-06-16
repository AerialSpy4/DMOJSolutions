#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;

#define endl "\n"

int planks[1000005];

int b[10001], h[10001];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n+1; i++) {
        cin >> h[i];
    }

    for (int i=0; i<n; i++) {
        cin >> b[i];
    }

    double ans = 0;

    for (int i=0; i<n; i++) {
        ans += (h[i]+h[i+1])/2.0 * b[i];
    }

    cout << fixed << ans << endl;
}