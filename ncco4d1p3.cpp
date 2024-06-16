#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;
const int INF = 2e9;

#define endl "\n"

// Shortest and second shortest distance
int distances[20005], distances2[20005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<pair<int, int>>> adj;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});

    fill(distances, distances+n+2, 2e9);
    fill(distances2, distances2+n+2, 2e9);
    distances[1] = 0;

    while (!q.empty()) {
        auto nodes = q.top(); q.pop();
        int d = nodes.first, node = nodes.second;

        for (auto i : adj[node]) {
            int a = i.first, b = i.second;

            // New distance is less than shortest distance
            if (distances[node]+b < distances[a]) {
                distances2[a] = distances[a];
                distances[a] = distances[node]+b;
                q.push({distances[a], a});
            // New distance is less than second shortest distance
            } else if (distances[node] + b != distances[a] && distances[node]+b < distances2[a]) {
                distances2[a] = distances[node]+b;
                q.push({distances2[a], a});
            }

            // Second shortest distance to old node plus new distance is less than second shortest distance to new node!
            if (distances2[node] + b != distances[a] && distances2[node] + b < distances2[a]) {
                distances2[a] = distances2[node]+b;
                q.push({distances2[a], a});
            }
        }
    }
    
    cout << distances2[n] << endl;
}