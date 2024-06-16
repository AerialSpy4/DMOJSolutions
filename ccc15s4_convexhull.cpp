#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;
const int INF = numeric_limits<int>::max();

#define endl "\n"

int distances[2005][505];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int k, n, m;
    cin >> k >> n >> m;

    for (int i=0; i<=n; i++) {
        for (int j=0; j<=k; j++) {
            distances[i][j] = 2e9;
        }
    }

    unordered_map<int, vector<tuple<int, int, int>>> adj;

    for (int i=0; i<m; i++) {
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        adj[a].push_back({b, t, h});
        adj[b].push_back({a, t, h});
    }

    int A, B;
    cin >> A >> B;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    q.push({0, A, 0});
    distances[A][0] = 0;

    while (!q.empty()) {
        auto nodes = q.top(); q.pop();
        int d = get<0>(nodes), node = get<1>(nodes), hull = get<2>(nodes);
        if (d > distances[node][hull]) {
            continue;
        }

        for (auto i : adj[node]) {
            int a = get<0>(i), b = get<1>(i), c = get<2>(i);
            if (hull + c < k && distances[node][hull] + b < distances[a][hull+c]) {
                distances[a][hull+c] = distances[node][hull]+b;
                q.push({distances[a][hull+c], a, hull+c});
            }
        }
    }

    int ans = 2e9;

    for (int kk=0; kk<k; kk++) {
        ans = min(ans, distances[B][kk]);
    }

    if (ans == 2e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}