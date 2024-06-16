#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;
const int INF = numeric_limits<int>::max();

#define endl "\n"
#define int long long

int p[MM], w[MM], d[MM], n;

int get_time(int c) {
    int t = 0;
    for (int i=0; i<n; i++) {
        if (c + d[i] < p[i]) {
            t += (p[i]-c-d[i]) * w[i];
        } else if (c - d[i] > p[i]) {
            t += (c-d[i]-p[i]) * w[i];
        }
    }

    return t;
}

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> p[i] >> w[i] >> d[i];
    }

    int l=0, r=1e9;
    int ans = 1e18;

    while (l <= r) {
        int mid = (l+r)/2;
        int t = get_time(mid);
        int t1 = get_time(mid+1);
        if (t < t1) {
            ans = min(ans, t);
            r = mid-1;
        } else {
            ans = min(ans, t1);
            l = mid+1;
        }
    }

    cout << ans << endl;
}