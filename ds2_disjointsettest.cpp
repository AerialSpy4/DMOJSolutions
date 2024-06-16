#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int p[MM], rk[MM];
int find_set(int d) {
    if (d != p[d]) {
        p[d] = find_set(p[d]);
    }
    return p[d];
}
void unite(int x, int y) {
    x = find_set(x); y = find_set(y);
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
    int N, M;
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        p[i] = i;
    }
    vector<int> edges;
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        if (find_set(a) != find_set(b)) {
            unite(a, b);
            edges.push_back(i+1);
        }
    }
    if (edges.size() != N-1) {
        cout << "Disconnected Graph" << '\n';
        return 0;
    }
    for (auto e : edges) {
        cout << e << '\n';
    }
}