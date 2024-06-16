#include <bits/stdc++.h>
using namespace std;
const int MM = 2e3+5;
vector<int> adj[MM];
bool vis[MM];
void dfs(int cur) {
    vis[cur] = true;
    for (auto nxt : adj[cur]) {
        if (!vis[nxt]) dfs(nxt);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for (int i=0, x, y; i<m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(a);
    cout << (vis[b] ? "GO SHAHIR!" : "NO SHAHIR!") << "\n";
}