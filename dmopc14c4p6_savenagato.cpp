#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
int N, end1, end2, endist1, endist2, dist[MM], dist2[MM];
vector<int> adj[MM];
void dfs1(int cur, int pre, int layer) {
    if (layer > endist1) {
        end1 = cur;
        endist1 = layer;
    }
    for (int nxt : adj[cur]) {
        if (nxt != pre) {
            dfs1(nxt, cur, layer+1);
        }
    }
}
void dfs2(int cur, int pre, int layer) {
    if (layer > endist2) {
        end2 = cur;
        endist2 = layer;
    }
    for (int nxt : adj[cur]) {
        if (nxt != pre) {
            dist[nxt] = dist[cur]+1;
            dfs2(nxt, cur, layer+1);
        }
    }
}
void dfs3(int cur, int pre) {
    for (int nxt : adj[cur]) {
        if (nxt != pre) {
            dist2[nxt] = dist2[cur]+1;
            dfs3(nxt, cur);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, -1, 1);
    dfs2(end1, -1, 1);
    dfs3(end2, -1);
    for (int i=1; i<=N; i++) {
        cout << max(dist[i], dist2[i])+1 << "\n";
    }
}