#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define endl "\n"
// #define int long long

// --
const int MX = 3000001;
int seconds = 0;
// --

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tt=0; tt<t; tt++) {
        int n; cin >> n;

        string people[n];
        unordered_map<string, vector<string>> adj;
        unordered_map<string, bool> visited;
        unordered_map<string, int> distances;

        for (int i=0; i<n; i++) {
            cin >> people[i];
        }

        string home = people[n-1];
        adj[people[0]].push_back(people[n-1]);
        adj[people[n-1]].push_back(people[0]);

        for (int i=0; i<n-1; i++) {
            adj[people[i]].push_back(people[i+1]);
        }

        queue<string> q;
        q.push(home);

        distances[home] = 0;
        visited[home] = true;

        int maxdist = 0;

        while (!q.empty()) {
            string node = q.front(); q.pop();
            maxdist = distances[node];
            for (auto i : adj[node]) {
                if (!visited[i]) {
                    visited[i] = true;
                    distances[i] = distances[node]+1;
                    q.push(i);
                }
            }
        }

        cout << 10 * (n-maxdist*2) << endl;
    }
}
