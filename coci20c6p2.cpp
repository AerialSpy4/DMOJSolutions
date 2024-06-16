#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;
const int INF = numeric_limits<int>::max();

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_map<string, vector<pair<string, int>>> adj;

    unordered_map<string, int> reference;

    for (int i=0; i<m; i++) {
        string a, b; int c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        reference[a] = 2e9;
        reference[b] = 2e9;
    }

    int queries;
    cin >> queries;

    for (int qq=0; qq<queries; qq++) {
        string X, Y;
        cin >> X >> Y;

        unordered_map<string, int> distances = reference;
        distances[X] = 0;

        unordered_map<string, bool> visited;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;
        q.push({0, X});

        while (!q.empty()) {
            auto nodes = q.top(); q.pop();
            int d = nodes.first; string node = nodes.second;
            if (d > distances[node]) {
                continue;
            }
            visited[node] = true;
            for (auto i : adj[node]) {
                string a = i.first; int b = i.second;
                if (distances[node]+b < distances[a]) {
                    distances[a] = distances[node]+b;
                    q.push({distances[a], a});
                }
            }
        }

        if (visited[Y]) {
            cout << distances[Y] << endl;
        } else {
            cout << "Roger" << endl;
        }
    }
}