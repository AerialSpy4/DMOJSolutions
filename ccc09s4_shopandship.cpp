#include <bits/stdc++.h>
using namespace std;

int distances[5005];
bool visited[5005];

#define endl "\n"

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    unordered_map<int, vector<pair<int, int>>> adj;

    for (int i=0; i<t; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int k;
    cin >> k;

    vector<pair<int, int>> cities;

    for (int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        cities.push_back({a, b});
    }

    int destination;
    cin >> destination;

    fill(distances, distances+n+2, 1e9);
    distances[destination] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, destination});

    while (!q.empty()) {
        auto nodes = q.top(); q.pop();
        int d = nodes.first, node = nodes.second;

        if (d > distances[node]) {
            continue;
        }

        visited[node] = true;

        for (auto i : adj[node]) {
            int x = i.first; int y = i.second;
            if (distances[node]+y < distances[x]) {
                distances[x] = distances[node]+y;
                q.push({distances[x], x});
            }
        }
    }

    int ans = 1e9;

    for (auto i : cities) {
        distances[i.first] += i.second;
        ans = min(ans, distances[i.first]);
    }

    cout << ans << endl;
}