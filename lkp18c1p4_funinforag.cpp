#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<tuple<int, int, int>>> adj;

    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c, i});
        adj[b].push_back({a, c, i});
    }

    // Get from station A to station B in less than C minutes

    int A, B, C;
    cin >> A >> B >> C;

    int lo = 0;
    int hi = m-1;

    int ans = 10000000000000;

    while (lo <= hi) {
        int mid = (lo+hi)/2;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        bool visited[100005] = {false};
        int distances[100005];
        fill(distances, distances+n+2, 10000000000000);
        
        // Distance, node
        q.push({0, A});
        distances[A] = 0;

        while (!q.empty()) {
            auto nodes = q.top(); q.pop();
            int d = nodes.first, node = nodes.second;
            if (d > distances[node]) {
                continue;
            }

            visited[node] = true;
            for (auto i : adj[node]) {
                int a = get<0>(i); int b = get<1>(i); int c = get<2>(i);
                if (c <= mid && distances[a] > distances[node]+b) {
                    distances[a] = distances[node]+b;
                    q.push({distances[a], a});
                }
            }
        }

        if (visited[B] && distances[B] < C) {
            ans = min(ans, mid);
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    if (ans == 10000000000000) {
        cout << -1 << endl;
    } else {
        cout << ans+1 << endl;
    }
}