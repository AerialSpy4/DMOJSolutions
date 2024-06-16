#include <bits/stdc++.h>
using namespace std;

int diff[30005][1005];

#define int long long

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i=0; i<k; i++) {
        int x, y, r, b;
        cin >> y >> x >> r >> b;
        // Loop every column
        for (int j=max(y-r, 0LL); j<=min(m, y+r); j++) {
            int lower = max(0LL, (int)ceil(1.0*x-sqrt(r*r - (y-j)*(y-j))));
            int upper = min(n+1, (int)floor(1.0*(x+sqrt(r*r - (y-j)*(y-j))))+1);
            diff[lower][j] += b;
            diff[upper][j] -= b;
        }
    }

    int maxbitrate = 0, cnt = 0;

    for (int i=0; i<=m; i++) {
        int curel = 0;
        for (int j=0; j<=n; j++) {
            curel += diff[j][i];
            if (curel > maxbitrate && i > 0 && j > 0) {
                maxbitrate = curel;
                cnt = 1;
            } else if (curel == maxbitrate && i > 0 && j > 0) {
                cnt++;
            }
        }
    }

    cout << maxbitrate << endl << cnt << endl;
}
