#include <bits/stdc++.h>
using namespace std;
const int MM = 30005;
int p[MM], c[MM], rk[MM], sz[MM], dist[MM];
int find_set(int d) {
    if (d != p[d]) {
        p[d] = find_set(p[d]);
    } 
    return p[d];
}
int find_child(int d) {
    if (d != c[d]) {
        return find_child(c[d]);
    }
    return c[d];
}
void unite(int x, int y) {
    x = find_set(x); y = find_child(y);
    p[x] = y;
    c[y] = x;
    y = find_set(y);
    // Keep finding child
    int i=0;
    int node = x;
    while (true) {
        dist[node] = sz[y]+i;
        i++;
        if (c[node] == node) break;
        node = c[node];
    }
    sz[y] += sz[x];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=1; i<=30000; i++) {
        p[i] = i;
        c[i] = i;
        sz[i] = 1;
    }
    while (t--) {
        char op; int a, b;
        cin >> op >> a >> b;
        if (op == 'M') {
            unite(a, b);
        } else {
            if (a == b) {
                cout << 0 << "\n";
            } else if (find_set(a) != find_set(b)) {
                cout << -1 << "\n";
            } else {
                cout << abs(dist[b] - dist[a]) - 1 << "\n";
            }
        }
    }
    // for (int i=1; i<=4; i++) {
    //     cout << dist[i] << " " << sz[find_set(i)] << "\n";
    // }
    // for (int i=1; i<=4; i++) {
    //     cout << c[i] << " ";
    // }
}