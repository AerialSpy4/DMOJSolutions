#include <bits/stdc++.h>
using namespace std;

#define endl "\n"


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<pair<int, int>> events;

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 0});
        events.push_back({b, 1});
    }

    sort(events.begin(), events.end());

    int cnt = 0, ans = 0;

    for (auto event : events) {
        if (event.second == 0) {
            cnt++;
            ans = max(ans, cnt);
        } else {
            cnt--;
        }
    }

    cout << ans << endl;
}