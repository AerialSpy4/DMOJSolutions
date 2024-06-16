#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 2e5+5;
int n, m, bit1[MM], bit2[MM], sum, ans[MM];
vector<array<int, 3>> events;
vector<int> rk;

void update(int bit[], int p, int v) {
    for (int i=p+1; i<MM; i+=i&-i) {
        bit[i] = min(bit[i], v);
    }
}
int query(int bit[], int p) {
    int ans = 1e18;
    for (int i=p+1; i>0; i-= i&-i) {
        ans = min(ans, bit[i]);
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        events.push_back({x, y, i+1});
        rk.push_back(y);
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        events.push_back({x, y, 0});
        rk.push_back(y);
    }
    sort(rk.begin(), rk.end());
    rk.resize(unique(rk.begin(), rk.end())-rk.begin());
    int sz = rk.size();
    for (auto &[x, y, id] : events) {
        y = lower_bound(rk.begin(), rk.end(), y) - rk.begin();
    }
    sort(events.begin(), events.end());
    memset(bit1, 0x3f, sizeof(bit1));
    memset(bit2, 0x3f, sizeof(bit2));
    for (auto [x, y, id] : events) {
        if (id == 0) {
            update(bit1, y, -x-rk[y]);
            update(bit2, sz-y, -x+rk[y]);
        } else {
            ans[id] = min(x+rk[y]+query(bit1, y), x-rk[y]+query(bit2, sz-y));
        }
    }
    reverse(events.begin(), events.end());
    memset(bit1, 0x3f, sizeof(bit1));
    memset(bit2, 0x3f, sizeof(bit2));
    for (auto [x, y, id] : events) {
        if (id == 0) {
            update(bit1, y, x-rk[y]);
            update(bit2, sz-y, x+rk[y]);
        } else {
            ans[id] = min(ans[id], min(-x+rk[y]+query(bit1, y), -x-rk[y]+query(bit2, sz-y)));
        }
    }
    for (int i=1; i<=n; i++) {
        sum += ans[i];
    }
    cout << sum << '\n';
}
