#include <bits/stdc++.h>
using namespace std;
// Try constructing it layer by layer, but each construction loops through all components with type i
vector<pair<int, int>> arr[10];
int dp[6][3005];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, N;
    cin >> T >> N;
    for (int i=0; i<N; i++) {
        int c, v, t;
        cin >> c >> v >> t;
        arr[t].push_back({c, v});
    }
    int B;
    cin >> B;
    for (int tp=1; tp<=T; tp++) {
        // Knapsack maybe
        auto vec = arr[tp];
        if (vec.size() == 0) {
            cout << -1 << '\n';
            return 0;
        }
        for (int i=0; i<vec.size(); i++) {
            auto [c, v] = vec[i];
            for (int i=0; i<=B; i++) {
                if (i-c >= 0) {
                    dp[tp][i] = max(dp[tp][i], max(dp[tp-1][i], dp[tp-1][i-c]+v));
                } else {
                    dp[tp][i] = max(dp[tp][i], dp[tp-1][i]);
                }
            }
        }
    }
    cout << dp[T][B] << '\n';
}
