#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int tt=0; tt<5; tt++) {
        int n;
        cin >> n;

        unordered_map<string, vector<pair<string, int>>> adj;

        for (int i=0; i<n; i++) {
            string a, b; int c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
        }

        // YYZ to SEA

        unordered_map<string, int> distances;

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> q;
        q.push({0, "YYZ"});
        distances["YYZ"] = 0;

        while (!q.empty()) {
            auto nodes = q.top(); q.pop();
            int d = nodes.first; string node = nodes.second;
            if (d > distances[node]) {
                continue;
            }

            for (auto i : adj[node]) {
                string a = i.first; int b = i.second;
                if (!distances.count(a)) {
                    distances[a] = 2e9;
                }
                if (distances[node]+b < distances[a]) {
                    distances[a] = distances[node]+b;
                    q.push({distances[a], a});
                }
            }
        }

        cout << distances["SEA"] << endl;
    }
}