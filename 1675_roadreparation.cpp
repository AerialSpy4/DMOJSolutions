#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MM = 2e5+5;


typedef tuple<int ,int, int> tup; // Weight, A, B

int p[MM], rk[MM];

int find_set(int d) {
    if (d != p[d]) {
        p[d] = find_set(p[d]);
    }
    return p[d];
}

void unite(int x, int y) {
    if (rk[x] > rk[y]) {
        p[y] = x;
    } else {
        p[x] = y;
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

    int n, m;
    cin >> n >> m;

    vector<tup> edges;

    for (int i=0; i<n; i++) {
        p[i] = i;
        rk[i] = 0;
    }

    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }

    sort(edges.begin(), edges.end());

    vector<tup> mst;

    int ans = 0;
    int cnt = 0;

    for (auto edge : edges) {
        int c = get<0>(edge), a = get<1>(edge), b = get<2>(edge);
        if (find_set(a) != find_set(b)) {
            link(a, b);
            mst.push_back({a, b, c});
            ans += c;
            cnt ++;
        }
    }

    if (cnt == n-1) {
        cout << ans << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}


/*
INPUT:

8 13
1 2 1
1 3 5
2 3 3
2 4 4
3 4 2
3 5 7
4 5 6
4 7 6
5 6 5
5 7 8
6 7 7
6 8 2
7 8 1

*/