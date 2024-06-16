#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<array<int, 3>> points;

    for (int i=0; i<n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        points.push_back({x, y, r});
    }

    unordered_map<int, vector<int>> adj;

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (pow((points[i][0] - points[j][0]), 2) + pow((points[i][1] - points[j][1]), 2) <= pow(points[i][2], 2)) {
                adj[i+1].push_back(j+1);
            }if (pow((points[i][0] - points[j][0]), 2) + pow((points[i][1] - points[j][1]), 2) <= pow(points[j][2], 2)) {
                adj[j+1].push_back(i+1);
            }
        }
    }

    for (int qq=0; qq<q; qq++) {
        int A, B;
        cin >> A >> B;

        queue<int> q;
        q.push(A);
        bool visited[1005] = {false};
        visited[A] = true;
        
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (auto i : adj[node]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        if (visited[B]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}