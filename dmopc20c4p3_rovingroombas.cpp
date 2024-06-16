#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define int long long

const int MM = 2e5+5;

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    ordered_set available;
    vector<tuple<int, int, int>> events;

    // Horizontal Lines
    for (int i=0; i<n; i++) {
        int y, len;
        cin >> len >> y;
        events.push_back({len, 1, y});
        available.insert(y);
    }

    // Vertical lines
    for (int i=0; i<m; i++) {
        int x, len;
        cin >> x >> len;
        events.push_back({x, 0, len});
    }

    sort(events.begin(), events.end());

    int ans = 0;

    for (auto event : events) {
        int x = get<0>(event), type = get<1>(event), temp = get<2>(event);
        if (type == 0) {
            // Query
            ans += available.order_of_key(temp+1);
        } else {
            available.erase(*available.find(temp));
        }
    }

    cout << ans << endl;
}