#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;
const int INF = numeric_limits<int>::max();

int distances[100005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, g;
    cin >> t >> n >> m >> g;

    fill(distances, distances+n+2, INF);

    vector<int> destinations;

    for (int i=0; i<g; i++) {
        int tmp; cin >> tmp;
        destinations.push_back(tmp);
    }

    unordered_map<int, vector<pair<int, int>>> adj;

    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    // Dijkstra from 0

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

    int ans = 0;

    for (auto i : destinations) {
        if (distances[i] <= t) {
            ans++;
        }
    }

    cout << ans << endl;
}