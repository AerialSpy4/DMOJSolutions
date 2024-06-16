#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 5e3+5;
int grid[MM][MM], diff[MM][MM], psa[MM][MM];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    while (k--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a++; b++; c++; d++;
        diff[a-1][b-1]++;
        diff[a-1][d]--;
        diff[c][b-1]--;
        diff[c][d]++;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            diff[i][j] = diff[i][j] + diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            diff[i][j] = diff[i][j] + diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1];
        }
    }
    int q; cin >> q;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << diff[c][d]-diff[a-1][d]-diff[c][b-1]+diff[a-1][b-1] << "\n";
    }
}