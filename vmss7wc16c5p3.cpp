#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define endl "\n"

bool visited[10005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int, vector<int>> adj;

    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    // Get diameter

    queue<int> q;
    q.push(1);
    visited[1] = true;
    int furthest = 1;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        furthest = node;

        for (auto i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    q.push(furthest);
    fill(visited, visited+n+1, false);
    visited[furthest] = true;
    int distances[10005] = {0};

    int furthest2 = furthest;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        furthest2 = node;

        for (auto i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                distances[i] = distances[node]+1;
                q.push(i);
            }
        }
    }

    cout << distances[furthest2] << endl;
}