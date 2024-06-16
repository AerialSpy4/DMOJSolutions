#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 1e5+5;
vector<pair<int, int>> adj[MM];
int sz[MM], vis[MM], ans;
unordered_map<int, int> dists;
int getSize(int cur, int pre) {
    sz[cur] = 1;
    for (auto node : adj[cur]) {
        int nxt = node.first, d = node.second;
        if (nxt != pre && !vis[nxt]) {
            sz[cur] += getSize(nxt, cur);
        }
    }
    return sz[cur];
}
int centroid(int cur, int pre, int total) {
    for (auto node : adj[cur]) {
        int nxt = node.first;
        if (nxt != pre && !vis[nxt] && sz[nxt] * 2 > total) {
            return centroid(nxt, cur, total);
        }
    }
    return cur;
}
void dfs(int cur, int pre, int d, vector<int>& path) {
    ans += dists[1-d] + dists[-1-d];
    path.push_back(d);
    for (auto node : adj[cur]) {
        int nxt = node.first, w = node.second;
        if (nxt != pre && !vis[nxt]) {
            dfs(nxt, cur, d+w, path);
        }
    }
}
void solve(int cur) {
    getSize(cur, 0);
    cur = centroid(cur, -1, sz[cur]);
    vis[cur] = true;
    dists.clear();
    dists[0] = 1;
    for (auto node : adj[cur]) {
        int nxt = node.first, w = node.second;
        vector<int> path;
        if (!vis[nxt]) {
            dfs(nxt, cur, w, path);
                for (auto p : path) {
                dists[p]++;
            }
        }
    }
    for (auto nxt : adj[cur]) {
        if (!vis[nxt.first]) {
            solve(nxt.first);
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b; char oc;
        cin >> a >> b >> oc;
        int c = (oc == 'r' ? 1 : -1);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    solve(1);
    cout << ans - (n-1) << "\n";
}