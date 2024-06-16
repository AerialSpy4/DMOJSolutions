#include <bits/stdc++.h>
using namespace std;
#define DEBUG cout << "checkpoint" << endl
const int MM = 2e5+5;
int sz[MM], ans = 2e9, n, k;
vector<pair<int, int>> adj[MM];
bool vis[MM];
map<int, int> dists;
vector<pair<int, int>> path;
void getsize(int cur, int pre) {
    sz[cur] = 1;
    for (auto [nxt, d] : adj[cur]) {
        if (nxt != pre && !vis[nxt]) {
            getsize(nxt, cur);
            sz[cur] += sz[nxt];
        }
    }
}
int centroid(int cur, int pre, int total) {
    for (auto [nxt, d] : adj[cur]) {
        if (nxt != pre && !vis[nxt] && sz[nxt]*2 > total) {
            return centroid(nxt, cur, total);
        }
    }
    return cur;
}
void dfs(int cur, int pre, int d, int de) {
    if (d > k) return;
    if (dists.count(k-d)) ans = min(ans, de + dists[k-d]);
    path.push_back({d, de});
    for (auto [nxt, w] : adj[cur]) {
        if (nxt != pre && !vis[nxt]) {
            dfs(nxt, cur, d+w, de+1);
        }
    }
}
void solve(int cur) {
    getsize(cur, -1);
    cur = centroid(cur, -1, sz[cur]);
    vis[cur] = true;
    dists.clear();
    dists[0] = 0;
    for (auto [nxt, w] : adj[cur]) {
        if (!vis[nxt]) {
            path.clear();
            dfs(nxt, cur, w, 1);
            for (auto [d, de] : path) {
                if (!dists.count(d)) {
                    dists[d] = de;
                } else {
                    dists[d] = min(dists[d], de);
                }
            }
        }
            
    }
    for (auto [nxt, w] : adj[cur]) {
        if (!vis[nxt]) {
            solve(nxt);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    solve(0);
    if (ans > n-1) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}