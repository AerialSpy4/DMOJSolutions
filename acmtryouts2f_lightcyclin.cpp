#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 1e6+5;
int bit[MM];
void update(int p, int v) {
    for (int i=p; i<=MM; i+=i&-i) {
        bit[i] += v;
    }
}
int query(int p) {
    int ans = 0;
    for (int i=p; i>0; i-=i&-i) {
        ans += bit[i];
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<array<int, 4>> events;
        for (int tt=0; tt<2; tt++) {
            fill(bit, bit+MM, 0);
            int x, y, n;
            cin >> x >> y >> n;
            for (int i=0; i<n; i++) {
                char op; int num;
                cin >> op >> num;
                // 0: opening, 1: vertical, 2: closing
                if (op == 'U') {
                    events.push_back({1, x, y, y+num});
                    y += num;
                } else if (op == 'D') {
                    events.push_back({1, x, y-num, y});
                    y -= num;
                } else if (op == 'L') {
                    events.push_back({0, x-num, y, 12345});
                    events.push_back({2, x, y, 12345});
                    x -= num;
                } else if (op == 'R') {
                    events.push_back({0, x, y, 12345});
                    events.push_back({2, x+num, y, 12345});
                    x += num;
                }
            }
        }
        sort(events.begin(), events.end(), [](auto a, auto b) {
            if (a[1] == b[1]) {
                return a[0] < b[0];
            }
            return a[1] < b[1];
        });
        int ans = 0;
        for (auto ev : events) {
            int op = ev[0];
            if (op == 0) {
                int x = ev[1], y = ev[2];
                update(y, 1);
            } else if (op == 1) {
                int x = ev[1], y1 = ev[2], y2 = ev[3];
                ans += query(y2-1)-query(y1);
            } else if (op == 2) {
                int x = ev[1], y = ev[2];
                update(y, -1);
            }
        }
        cout << ans << "\n";
    }
}
