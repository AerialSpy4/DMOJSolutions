#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const int MM = 2005;
int n, x[MM], y[MM], pre[MM], temp[MM], dp[MM];
vector<array<int, 3>> ev;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i=0; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            int d = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
            ev.push_back({d, i, j});
        }
    }
    sort(ev.begin(), ev.end());
    for (auto e : ev) {
        int d = e[0], i = e[1], j = e[2];
        if (d > pre[i]) {
            pre[i] = d;
            temp[i] = dp[i];
        } if (d > pre[j]) {
            pre[j] = d;
            temp[j] = dp[j];
        } if (i != 0) {
            dp[j] = max(dp[j], temp[i]+1);
        }
        dp[i] = max(dp[i], temp[j]+1);;
    }
    cout << dp[0] << "\n";
}