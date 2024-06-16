#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int l, n;
    cin >> l >> n;

    vector<pair<int, int>> events;

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;

        events.push_back({a, 1});
        events.push_back({b, -1});
    }

    sort(events.begin(), events.end());

    int cnt = 0, prev = 0, ans = 0;

    for (auto event : events) {
        if (event.second == 1) {
            if (cnt == 0) {
                ans = max(ans, event.first - prev);
            }
            cnt++;
        } else {
            cnt--;
            if (cnt == 0) {
                prev = event.first;
            }
        }
    }

    cout << max(ans, l-events[events.size()-1].first) << endl;
}