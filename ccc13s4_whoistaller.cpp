#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

bool visited[100005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> adj;

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int A, B;
    cin >> A >> B;

    queue<int> q;

    q.push(A);
    visited[A] = true;

    while (!q.empty()) {
        auto node = q.front(); q.pop();
        for (auto i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    if (visited[B]) {
        cout << "yes" << endl;
        return 0;
    }

    fill(visited, visited+n+2, false);

    q.push(B);
    visited[B] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (auto i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    if (visited[A]) {
        cout << "no" << endl;
    } else {
        cout << "unknown" << endl;
    }
}