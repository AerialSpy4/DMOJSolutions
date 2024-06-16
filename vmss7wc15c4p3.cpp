#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;
const int INF = numeric_limits<int>::max();

int distances[100005];
int distances2[100005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    fill(distances, distances+n+2, 2e9);

    unordered_map<int, vector<pair<int, int>>> adj;

    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    // dijkstra from 0 to every node then n-1 to every node

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, 0});
    distances[0] = 0;

    while (!q.empty()) {
        auto nodes = q.top(); q.pop();
        int d = nodes.first; int node = nodes.second;

        if (d > distances[node]) {
            continue;
        }

        for (auto i : adj[node]) {
            int a = i.first; int b = i.second;

            if (distances[node]+b < distances[a]) {
                distances[a] = distances[node]+b;
                q.push({distances[a], a});
            }
        }
    }

    q.push({0, n-1});
    fill(distances2, distances2+n+2, 2e9);
    distances2[n-1] = 0;

    while (!q.empty()) {
        auto nodes = q.top(); q.pop();
        int d = nodes.first; int node = nodes.second;

        if (d > distances2[node]) {
            continue;
        }

        for (auto i : adj[node]) {
            int a = i.first; int b = i.second;

            if (distances2[node]+b < distances2[a]) {
                distances2[a] = distances2[node]+b;
                q.push({distances2[a], a});
            }
        }
    }

    int ans = 0;

    for (int i=0; i<n; i++) {
        ans = max(ans, distances[i] + distances2[i]);
    }

    cout << ans << endl;
}