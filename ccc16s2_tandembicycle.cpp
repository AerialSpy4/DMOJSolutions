#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;

#define endl "\n"

int a[105], b[105];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int q, n;
    cin >> q >> n;

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    for (int i=0; i<n; i++) {
        cin >> b[i];
    }

    if (q == 2) {
        sort(a, a+n);
        sort(b, b+n, greater<>());
    } else if (q == 1) {
        sort(a, a+n);
        sort(b, b+n);
    }

    int ans = 0;

    for (int i=0; i<n; i++) {
        ans += max(a[i], b[i]);
    }

    cout << ans << endl;
}