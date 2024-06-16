#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 4e5+5;
int n, dist[MM], cnt[MM], dia, num;
vector<int> adj[MM];
void dfs(int u, int par) {
    dist[u] = 0; cnt[u] = 1;
    for (auto v : adj[u]) {
        if (v == par) continue;
        dfs(v, u);
        if (dist[u] + dist[v] + 1 > dia) {
            dia = dist[u] + dist[v] + 1;
            num = cnt[u] * cnt[v];
        } else if (dist[u] + dist[v] + 1 == dia) {
            num += cnt[u] * cnt[v];
        }
        if (dist[v]+1 > dist[u]) {
            dist[u] = dist[v] + 1;
            cnt[u] = cnt[v];
        } else if (dist[v]+1 == dist[u]) {
            cnt[u] += cnt[v];
        }
    }
}
void solve() {
    cin >> n;
    for (int i=1, u, v; i<n; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << dia + 1 << " " << num << "\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}