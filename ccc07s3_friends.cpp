#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int, int> adj;

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a] = b;
    }

    while (true) {
        int a, b;
        cin >> a >> b;

        if (!a && !b) {
            break;
        }

        bool visited[10005] = {false};
        int distances[10005] = {0};

        queue<int> q;
        q.push(a);
        visited[a] = true;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            if (adj.count(node) && !visited[adj[node]]) {
                visited[adj[node]] = true;
                distances[adj[node]] = distances[node]+1;
                q.push(adj[node]);
            }
        }

        if (visited[b]) {
            cout << "Yes " << distances[b]-1 << endl;
        } else {
            cout << "No" << endl;
        }
    }
}