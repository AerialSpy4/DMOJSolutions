#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> adj = {{}, {6}, {6}, {4,5,6,15}, {3,5,6}, {3,4,6}, {1,2,3,4,5,7}, {6,8}, {7,9}, {8,10,12}, {9,11}, {10,12}, {9,11,13}, {12,14,15}, {13}, {3,13}, {17,18}, {16,18}, {16,17}};

    for (int i=0; i<40; i++) {
        adj.push_back({});
    }

    while (true) {
        char type;
        cin >> type;
        if (type == 'i') {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        } else if (type == 'd') {
            int x, y;
            cin >> x >> y;
            adj[x].erase(remove(adj[x].begin(), adj[x].end(), y), adj[x].end());
            adj[y].erase(remove(adj[y].begin(), adj[y].end(), x), adj[y].end());
        } else if (type == 'n') {
            int x;
            cin >> x;
            cout << adj[x].size() << endl;
        } else if (type == 'f') {
            // Distance 2
            int distances[100] = {0};
            bool visited[100] = {false};

            queue<int> q;

            int x;
            cin >> x;

            visited[x] = true;
            q.push(x);

            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (auto i : adj[node]) {
                    if (!visited[i]) {
                        visited[i] = true;
                        distances[i] = distances[node]+1;
                        q.push(i);
                    }
                }
            }

            int ans = 0;

            for (int i=0; i<=50; i++) {
                if (distances[i] == 2) {
                    ans++;
                }
            }

            cout << ans << endl;
        } else if (type == 's') {
            int distances[105] = {0};
            bool visited[105] = {false};
            int x, y;
            cin >> x >> y;

            queue<int> q;
            q.push(x);
            visited[x] = true;

            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (auto i : adj[node]) {
                    if (!visited[i]) {
                        visited[i] = true;
                        distances[i] = distances[node]+1;
                        q.push(i);
                    }
                }
            }

            if (!visited[y]) {
                cout << "Not connected" << endl;
            } else {
                cout << distances[y] << endl;
            }
        } else {
            break;
        }
    }
}