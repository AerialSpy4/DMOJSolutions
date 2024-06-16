#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int sz[MM];
vector<int> adj[MM];
void dfs(int cur, int pre) {
    sz[cur] = 1;
    for (auto nxt : adj[cur]) {
        if (nxt != pre) {
            dfs(nxt, cur);
            sz[cur] += sz[nxt];
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    int maxsz = 2e9, maxnode = 0;
    for (int i=1; i<=n; i++) {
        if (sz[i]*2 > n && sz[i]*2 < maxsz) {
            maxnode = i;
            maxsz = sz[i]*2;
        }
    }
    cout << maxnode << '\n';
}