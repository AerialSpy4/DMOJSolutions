#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;
const int INF = 2e9;

#define endl "\n"

int dest[100005];
int distances[100005], distances2[100005];
bool visited[100005], visited2[100005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, A, B;
    cin >> n >> m >> k >> A >> B;

    for (int i=0; i<k; i++) {
        cin >> dest[i];
    }

    unordered_map<int, vector<int>> adj;

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Bfs from A and from B then add up

    queue<int> q;
    q.push(A);
    visited[A] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (auto i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
                distances[i] = distances[node]+1;
            }
        }
    }

    q.push(B);
    visited2[B] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (auto i : adj[node]) {
            if (!visited2[i]) {
                visited2[i] = true;
                q.push(i);
                distances2[i] = distances2[node]+1;
            }
        }
    }

    int ans = 2e9;

    for (int i=0; i<k; i++) {
        ans = min(ans, distances[dest[i]] + distances2[dest[i]]);
    }

    cout << ans << endl;
}