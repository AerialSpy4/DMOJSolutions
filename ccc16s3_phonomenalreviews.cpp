#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;

#define endl "\n"

bool pho[100005], visited[100005];
int distances[100005];
unordered_map<int, vector<int>> adj;

void prunedfs(int cur, int pre) {
    for (auto i : adj[cur]) {
        if (i != pre) {
            prunedfs(i, cur);
            if (pho[i]) {
                pho[cur] = true;
            }
        }
    }
}

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int start = 0;

    for (int i=0; i<m; i++) {
        int temp; cin >> temp;
        pho[temp] = true;
        start = temp;
    }

    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Prune
    prunedfs(start, -1);

    int cnt = 0;

    for (int i=0; i<n; i++) {
        if (pho[i]) {
            cnt++;
        }
    }

    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    int newstart = 0;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        newstart = node;
        for (auto i : adj[node]) {
            if (!visited[i] && pho[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    int d = 0;

    fill(visited, visited+n+2, false);

    q.push(newstart);
    visited[newstart] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        d = distances[node];
        for (auto i : adj[node]) {
            if (!visited[i] && pho[i]) {
                q.push(i);
                visited[i] = true;
                distances[i] = distances[node]+1;
            }
        }
    }

    cout << 2 * (cnt-1) - d << endl;
}