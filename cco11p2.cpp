#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

// Distance, exposure
int distances[1605][3605];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int s, n, e;
    cin >> s >> n >> e;

    unordered_map<int, vector<array<int, 3>>> adj;

    for (int i=0; i<e; i++) {
        int a, b, d, u;
        cin >> a >> b >> d >> u;
        adj[a].push_back({b, d, u});
        adj[b].push_back({a, d, u});
    }

    for (int i=0; i<1601; i++) {
        for (int j=0; j<=3601; j++) {
            distances[i][j] = 2e9;
        }
    }

    // Distance, node, exposure
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
    q.push({0, 0, 0});
    distances[0][0] = 0;

    while (!q.empty()) {
        auto nodes = q.top(); q.pop();
        int d = nodes[0], node = nodes[1], sun = nodes[2];

        if (d > distances[node][sun]) {
            continue;
        }

        for (auto i : adj[node]) {
            int a = i[0], b = i[1], cursun = i[2];
            if (sun+cursun*b <= s && distances[node][sun] + b < distances[a][sun+cursun*b]) {
                distances[a][sun+cursun*b] = distances[node][sun] + b;
                q.push({distances[a][sun+cursun*b], a, sun+cursun*b});
            }
        }
    }

    int ans = 2e9;

    for (int i=0; i<=s; i++) {
        ans = min(ans, distances[n-1][i]);
    }

    if (ans == 2e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}