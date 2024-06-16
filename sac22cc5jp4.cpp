#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define endl "\n"

int in[200005];

int32_t main() {
    int n;
    scan(n);

    unordered_map<int, vector<int>> adj;

    for (int i=0; i<n; i++) {
        int m;
        scan(m);

        if (m == 0) {
            continue;
        } else {
            for (int j=0; j<m; j++) {
                int temp; scan(temp);
                adj[temp].push_back(i+1);
                in[i+1]++;
            }
        }
    }

    queue<int> q;

    for (int i=1; i<=n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";
        for (auto i : adj[node]) {
            if (--in[i] == 0) {
                q.push(i);
            }
        }
    }
}