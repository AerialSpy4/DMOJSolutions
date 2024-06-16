#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, l, s;
    cin >> n >> l >> s;

    vector<pair<int, int>> events;

    for (int i=0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        events.push_back({a, c});
        events.push_back({b+1, -c});
    }

    sort(events.begin(), events.end());

    int curspook = 0;
    int prevevent = 1;

    // Get the ones that are too spooky

    int ans = 0;

    for (auto event : events) {
        int a = event.first, c = event.second;
        if (curspook >= s) {
            ans += a-prevevent;
        }
        prevevent = a;
        curspook += c;
    }

    cout << l-ans << endl;
}