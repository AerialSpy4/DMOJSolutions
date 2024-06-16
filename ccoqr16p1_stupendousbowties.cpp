#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 1e5+5;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> points;
    int ans = 0;
    unordered_map<int, vector<int>> xcords, ycords;
    unordered_map<int, bool> xsorted, ysorted;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        xcords[x].push_back(y);
        ycords[y].push_back(x);
        points.push_back({x, y});
    }
    for (auto p : points) {
        int x = p.first, y = p.second;
        if (!xsorted[x]) {sort(xcords[x].begin(), xcords[x].end()); xsorted[x] = true;}
        if (!ysorted[y]) {sort(ycords[y].begin(), ycords[y].end()); ysorted[y] = true;}
        int ylower = lower_bound(xcords[x].begin(), xcords[x].end(), y)-xcords[x].begin();
        int yhigher = xcords[x].size() - ylower - 1;
        int xlower = lower_bound(ycords[y].begin(), ycords[y].end(), x) - ycords[y].begin();
        int xhigher = ycords[y].size() - xlower - 1;
        ans += yhigher*ylower*xhigher*xlower;
    }
    cout << ans*2 << "\n";
}