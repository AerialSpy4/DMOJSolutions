#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MM = 2e5+5;
const int INF = 1e12;

int distances[500005], distances2[500005];
bool visited[500005], visited2[500005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<pair<int, int>>> adj, adjrev;

    // Not secret path edges

    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adjrev[b].push_back({a, c});
    }

    // Secret path edges

    vector<pair<int, pair<int, int>>> edges;
    int d;
    cin >> d;

    for (int i=0; i<d; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, {b, c}});
    }

    // Dijkstra from 1, then dijkstra from n, then check distance from endpoints of each edge

    fill(distances, distances+n+2, INF);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    distances[1] = 0;

    while (!q.empty()) {
        auto nodes = q.top(); q.pop();
        int d = nodes.first, node = nodes.second;

        if (d > distances[node]) {
            continue;
        }
        visited[node] = true;

        for (auto i : adj[node]) {
            int a = i.first, b = i.second;
            if (distances[node] + b < distances[a]) {
                distances[a] = distances[node] + b;
                q.push({distances[a], a});
            }
        }
    }
    

    fill(distances2, distances2+n+2, INF);

    q.push({0, n});
    distances2[n] = 0;

    while (!q.empty()) {
        auto nodes = q.top(); q.pop();
        int d = nodes.first, node = nodes.second;

        if (d > distances2[node]) {
            continue;
        }
        visited2[node] = true;

        for (auto i : adjrev[node]) {
            int a = i.first, b = i.second;
            if (distances2[node] + b < distances2[a]) {
                distances2[a] = distances2[node] + b;
                q.push({distances2[a], a});
            }
        }
    }

    int ans = INF;

    for (auto edge : edges) {
        int a = edge.first, b = edge.second.first, c = edge.second.second;
        if (visited[a] && visited2[b]) {
            ans = min(ans, distances[a] + distances2[b] + c);
        }
    }

    if (ans == INF && !visited[n]) {
        cout << -1 << endl;
    } else {
        cout << min(ans, distances[n]) << endl;
    }
}