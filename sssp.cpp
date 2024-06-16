#include <bits/stdc++.h>
using namespace std;

int distances[5005];
bool visited[5005];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;

    fill(distances, distances+n+2, 1e9);

    unordered_map<int, vector<pair<int, int>>> adj;

    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    distances[1] = 0;

    while (!q.empty()) {
        auto node1 = q.top(); q.pop();
        int node = node1.second; int distance = node1.first;
        if (distance > distances[node]) {
            continue;
        }
        visited[node] = true;
        for (auto i : adj[node]) {
            int a = i.first; int b = i.second;
            if (distances[a] > distances[node]+b) {
                distances[a] = distances[node]+b;
                q.push({distances[a], a});
            }
        }
    }

    for (int i=1; i<=n; i++) {
        if (visited[i]) {
            cout << distances[i] << endl;
        } else {
            cout << -1 << endl;
        }
    }
}