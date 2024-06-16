#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
vector<pair<int, int>> adj[MM];
int d1[MM], d2[MM], ans[MM], edges[MM];
void dfs1(int u, int par){
    for(auto [v, w] : adj[u]){
        if(v == par) continue;
        dfs1(v, u);
        if(d1[v] + w > d1[u]) { d2[u] = d1[u]; d1[u] = d1[v] + w; }
        else if(d1[v] + w > d2[u]) d2[u] = d1[v] + w;
    }
}
void dfs2(int u, int par, int plen) {
    ans[u] = max(d1[u], plen);
    for(auto [v, w] : adj[u]){
        if(v == par) continue;
        if(d1[v] + w == d1[u]) dfs2(v, u, max(plen, d2[u]) + w);
        else dfs2(v, u, max(plen, d1[u]) + w);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, T;
    cin >> N >> T;
    int allweights = 0;
    for (int i=0; i<N-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        edges[a]++; edges[b]++;
        allweights += c;
    }
    dfs1(1, -1);
    dfs2(1, 0, 0);
    for (int i=1; i<=N; i++) {
        if (edges[i] == T) {
            cout << i << " " << allweights*2-ans[i] << '\n';
        }
    }
}
