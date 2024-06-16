#include <bits/stdc++.h>
using namespace std;

int distances[2005];
bool visited[2005];

#define endl "\n"

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, b, Q;
    cin >> n >> m >> b >> Q;

    fill(distances, distances+n+2, 1e9);

    unordered_map<int, vector<pair<int, int>>> adj;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> q;
    q.push({0, b});

    distances[b] = 0;

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

    for (int i=0; i<Q; i++) {
        int temp; cin >> temp;
        if (!visited[temp]) {
            cout << -1 << endl;
        } else {
            cout << distances[temp] << endl;
        }
    }
}