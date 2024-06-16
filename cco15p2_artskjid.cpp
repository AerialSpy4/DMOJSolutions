#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 21;
int dp[MM][1 << MM];
vector<pair<int, int>> adj[MM];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    queue<pair<int, int>> q;
    // node, visited list in binary
    q.push({0, 1});
    while (!q.empty()) {
        auto [cur, vis] = q.front(); q.pop();
        for (auto [nxt, w] : adj[cur]) {
            if ((vis & (1 << nxt)) == 0) {
                int newvis = vis | (1 << nxt);
                if (dp[nxt][newvis] < dp[cur][vis] + w) {
                    dp[nxt][newvis] = dp[cur][vis] + w;
                    q.push({nxt, newvis});
                }
            }
        }
    }
    int ans = 0;
    for (int i=1; i<=(1<<N); i++) {
        ans = max(ans, dp[N-1][i]);
    }
    cout << ans << '\n';
}