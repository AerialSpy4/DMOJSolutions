/*
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+5;
int n, m, rt, cnt, leaf;
int vis[MM], dfn[MM], low[MM], d[MM];
vector<int> adj[MM];
void tar(int u, int fa){
    vis[u] = 1;
    dfn[u] = low[u] = cnt ++;
    for(int i = 0; i < adj[u].size(); i ++){
        int v = adj[u][i];
        if(vis[v] == 1 && v != fa)
            low[u] = min(low[u], dfn[v]);
        if(vis[v] == 0){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
    }
    vis[u] = 2;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r;
    for (int i=0; i<r; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}
*/
