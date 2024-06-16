#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
const int MM = 1e5+5;
int N, M, ranks[MM], p[MM], rk[MM];
unordered_map<int, ordered_set> sets;
unordered_map<int, int> ranktostudent;
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
        for (const int &i : sets[y]) {
            sets[x].insert(i);
        }
    } else {
        p[x] = y;
        for (const int &i : sets[x]) {
            sets[y].insert(i);
        }
        if (rk[x] == rk[y]) {
            rk[y]++;
        }
    }
}
void solve() {
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> ranks[i];
        ranktostudent[ranks[i]] = i;
    }
    for (int i=1; i<=N; i++) {
        sets[i] = {};
        sets[i].insert(ranks[i]);
        p[i] = i;
    }
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        if (find_set(a) != find_set(b)) {
            unite(a, b);
        }
    }
    int queries;
    cin >> queries;
    for (int qq=0; qq<queries; qq++) {
        char op; int x, y;
        cin >> op >> x >> y;
        if (op == 'B') {
            if (find_set(x) != find_set(y)) {
                unite(x, y);
            }
        } else {
            x = find_set(x);
            int ans = ranktostudent[*(sets[x].find_by_order(y-1))];
            if (ans == 0) cout << -1 << "\n";
            else {
                cout << ans << "\n";
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}