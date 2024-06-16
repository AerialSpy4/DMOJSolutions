#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> prices;

    for (int i=0; i<n; i++) {
        int price, discounted;
        cin >> price >> discounted;
        prices.push_back({discounted, price});
    }

    sort(prices.begin(), prices.end(), [](pair<int, int> a, pair<int, int> b) {
        return (a.second-a.first) > (b.second-b.first);
    });

    int ans = 0;

    for (int i=0; i<prices.size(); i++) {
        if (k) {
            k--;
            ans += prices[i].first;
        } else {
            ans += prices[i].second;
        }
    }

    cout << ans << endl;
}