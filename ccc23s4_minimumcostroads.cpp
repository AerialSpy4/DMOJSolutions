#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 2e3+5;
int n, m, p[MM], rk[MM], finalans, tocheck[MM];
vector<array<int, 3>> adj[MM];
vector<pair<int, int>> mst[MM];
vector<array<int, 4>> edges, check;
int find_set(int d) {
    if (p[d] != d) {
        p[d] = find_set(p[d]);
    }
    return p[d];
}
void unite(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (rk[x] > rk[y]) {
        p[y] = x;
    } else {
        p[x] = y;
        if (rk[x] == rk[y]) rk[y]++;
    }
}
void solve() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, l, c;
        cin >> a >> b >> l >> c;
        adj[a].push_back({b, l, c});
        adj[b].push_back({a, l, c});
        edges.push_back({a, b, l, c});
    }
    for (int i=1; i<=n; i++) {
        p[i] = i;
        rk[i] = 0;
    }
    sort(edges.begin(), edges.end(), [](auto a, auto b) {
        if (a[2] == b[2]) return a[3] < b[3];
        return a[2] < b[2];
    });
    int curedge = 0;
    for (auto edge : edges) {
        int a = edge[0], b = edge[1], l = edge[2], c = edge[3];
        if (find_set(a) != find_set(b)) {
            unite(a, b);
            mst[a].push_back({b, l});
            mst[b].push_back({a, l});
            finalans += c;
            tocheck[curedge] = 1;
        } else {
            int distances[2005];
            fill(distances, distances+2001, 1e18);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
            q.push({0, a});
            distances[a] = 0;
            while (!q.empty()) {
                auto nodes = q.top(); q.pop();
                int d = nodes.first, node = nodes.second;
                if (d > distances[node]) continue;
                for (auto i : mst[node]) {
                    int A = i.first, B = i.second;
                    if (distances[node]+B < distances[A]) {
                        distances[A] = distances[node] + B;
                        q.push({distances[A], A});
                    }
                }
            }
            if (distances[b] > l) {
                unite(a, b);
                mst[a].push_back({b, l});
                mst[b].push_back({a, l});
                finalans += c;
            }
        }
    }
    cout << finalans << "\n";
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}