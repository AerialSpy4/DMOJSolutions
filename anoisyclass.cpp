#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;
const int INF = numeric_limits<int>::max();

int in[10005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> adj;

    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        in[b]++;
        adj[a].push_back(b);
    }

    queue<int> q;

    for (int i=1; i<=n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    int counter = 0;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        counter++;

        for (auto i : adj[node]) {
            in[i]--;
            if (in[i] == 0) {
                q.push(i);
            }
        }
    }
    
    if (counter == n) {
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }
}