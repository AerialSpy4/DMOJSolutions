#include <bits/stdc++.h>
using namespace std;

#define int long long

int distances[100005];
bool visited[100005];

signed main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<pair<int, int>>> adj;

    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});

    fill(distances, distances+n+2, 1e16);
    distances[1] = 0;

    while (!q.empty()) {
        auto nodes = q.top(); q.pop();
        int d = nodes.first, node = nodes.second;

        if (d > distances[node]) {
            continue;
        }

        visited[node] = true;

        for (auto i : adj[node]) {
            int x = i.first, y = i.second;
            if (distances[node]+y < distances[x]) {
                distances[x] = distances[node]+y;
                q.push({distances[x], x});
            }
        }
    }

    for (int i=1; i<=n; i++) {
        cout << distances[i] << " ";
    }
}