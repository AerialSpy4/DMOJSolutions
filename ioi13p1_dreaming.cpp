#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
vector<pair<int, int>> adj[MM];
bool visited[MM], vis[MM], vis2[MM];
int dist[MM], dist2[MM], n, m, l;
void solve() {
    if (m == 0) {
        if (n == 1) {
            cout << 0 << "\n";
        } else if (n == 2) {
            cout << l << "\n";
        } else {
            cout << l*2 << "\n";
        }
        return;
    }
    vector<int> radii;
    // Get the diameter of each tree
    int furthestdia = 0;
    for (int curnode=0; curnode<n; curnode++) {
        if (visited[curnode]) continue;
        if (adj[curnode].empty()) {
            radii.emplace_back(0);
            continue;
        }
        queue<int> q;
        vector<int> nodes;
        memset(vis, 0, sizeof(vis));
        memset(dist, 0, sizeof(dist));
        q.push(curnode);
        vis[curnode] = true;
        visited[curnode] = true;
        // BFS furthest node
        int furthest = -1, maxdist = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            nodes.emplace_back(node);
            if (dist[node] > maxdist) {
                furthest = node;
                maxdist = dist[node];
            }
            for (auto i : adj[node]) {
                int b = i.first, c = i.second;
                if (!vis[b]) {
                    vis[b] = true;
                    visited[b] = true;
                    dist[b] = dist[node]+c;
                    q.push(b);
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        memset(dist, 0, sizeof(dist));
        q.push(furthest);
        vis[furthest] = true;
        int dia = 0, diafurthest = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            if (dist[node] > dia) {
                diafurthest = node;
                dia = dist[node];
            }
            for (auto i : adj[node]) {
                int b = i.first, c = i.second;
                if (!vis[b]) {
                    vis[b] = true;
                    dist[b] = dist[node]+c;
                    q.push(b);
                }
            }
        }
        // Minimize the maximum
        memset(vis, 0, sizeof(vis));
        memset(dist, 0, sizeof(dist));
        q.push(furthest);
        vis[furthest] = true;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (auto i : adj[node]) {
                int b = i.first, c = i.second;
                if (!vis[b]) {
                    vis[b] = true;
                    dist[b] = dist[node]+c;
                    q.push(b);
                }
            }
        }
        q.push(diafurthest);
        vis2[diafurthest] = true;
        int radius = 2e9;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            radius = min(radius, max(dist[node], dist2[node]));
            for (auto i : adj[node]) {
                int b = i.first, c = i.second;
                if (!vis2[b]) {
                    vis2[b] = true;
                    dist2[b] = dist2[node]+c;
                    q.push(b);
                }
            }
        }
        radii.emplace_back(radius);
        furthestdia = max(furthestdia, dia);
    }
    if (radii.size() == 1) {
        cout << furthestdia;
        return;
    } else if (radii.size() == 2) {
        cout << max(radii[0] + radii[1] + l, furthestdia);
        return;
    }
    sort(radii.begin(), radii.end(), greater<int>());
    cout << max(radii[0] + radii[1] + l, max(furthestdia, radii[1]+radii[2]+2*l));
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> l;
    for (int i=0, a, b, c; i<m; i++) {
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    solve();
}