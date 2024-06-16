#include <bits/stdc++.h>
using namespace std;
const int MM = 4e5+5;
vector<pair<int, int>> edges, pre_edges;
vector<int> adj[MM];
bool addlater[MM], added[MM];
int p[MM], rk[MM];
int find_set(int d) {
    if (d != p[d]) {
        p[d] = find_set(p[d]);
    }
    return p[d];
}
void unite(int x, int y) {
    x = find_set(x), y = find_set(y);
    if (rk[x] > rk[y]) {
        p[y] = x;
    } else {
        p[x] = y;
        if (rk[x] == rk[y]) {
            rk[y]++;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        pre_edges.push_back({a, b});
    }
    for (int i=0; i<n; i++) {
        p[i] = i;
    }
    int k;
    cin >> k;
    deque<int> deletions;
    for (int i=0; i<k; i++) {
        int x; cin >> x;
        deletions.push_front(x);
        addlater[x] = true;
    }
    int curnodes = 0;
    for (int i=0; i<n; i++) {
        if (!addlater[i]) {
            curnodes++;
        }
    }
    int components = curnodes;
    for (auto edge : pre_edges) {
        int a = edge.first, b = edge.second;
        if (!addlater[a] && !addlater[b]) {
            edges.push_back(edge);
            if (find_set(a) != find_set(b)) {
                unite(a, b);
            }
            components--;
        }
    }
    vector<int> ans;
    while (!deletions.empty()) {
        int cur = deletions.back(); deletions.pop_back();
        for (auto i : adj[cur]) {
            if (!added[i] && find_set(i) != find_set(cur)) {
                unite(cur, i);
                components++;
            }
        }
        ans.push_back(components);
        added[cur] = true;
    }
    for (int i=ans.size()-1; i>=0; i--) {
        cout << ans[i] << "\n";
    }
}