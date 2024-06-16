#include <bits/stdc++.h>
using namespace std;

const int MM = 1e5+5;
const int INF = numeric_limits<int>::max();

#define endl "\n"

// Disjoint Set Union

int p[MM], rk[MM], group[MM];

int find_set(int d) {
    if (d != p[d]) {
        p[d] = find_set(p[d]);
    }
    return p[d];
}

void unite(int x, int y) {
    if (rk[x] > rk[y]) {
        p[y] = x;
        group[x] += group[y];
    } else {
        p[x] = y;
        group[y] += group[x];
        if (rk[x] == rk[y]) {
            rk[y]++;
        }
    }
}

void link(int x, int y) {
    unite(find_set(x), find_set(y));
}

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i=1; i<=n; i++) {
        p[i] = i;
        rk[i] = 0;
        group[i] = 1;
    }

    for (int i=0; i<q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x, y;
            cin >> x >> y;

            if (find_set(x) != find_set(y)) {
                link(x, y);
            }
        } else if (type == 2) {
            int x;
            cin >> x;
            cout << group[find_set(x)] << endl;
        }
    }
}