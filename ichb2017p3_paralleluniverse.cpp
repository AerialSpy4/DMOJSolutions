#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 1e5+5;
struct Node {int l, r, v;} seg[4*MM];
int arr[MM];
void build(int l, int r, int idx) {
    seg[idx].l = l; seg[idx].r = r;
    if (l == r) {
        seg[idx].v = arr[l];
    } else {
        int mid = (l+r)/2;
        build(l, mid, 2*idx);
        build(mid+1, r, 2*idx+1);
        seg[idx].v = seg[2*idx].v & seg[2*idx+1].v;
    }
}
void update(int pos, int val, int idx) {
    if (seg[idx].l == seg[idx].r) {
        seg[idx].v = val;
    } else {
        int mid = (seg[idx].l + seg[idx].r) / 2;
        if (pos <= mid) {
            update(pos, val, 2*idx);
        }  else {
            update(pos, val, 2*idx+1);
        }
        seg[idx].v = seg[2*idx].v & seg[2*idx+1].v;
    }
}
int query(int l, int r, int idx) {
    if (seg[idx].l == l && seg[idx].r == r) {
        return seg[idx].v;
    } else {
        int mid = (seg[idx].l + seg[idx].r) / 2;
        if (r <= mid) {
            return query(l, r, 2*idx);
        } else if (l > mid) {
            return query(l, r, 2*idx+1);
        } else {
            return (query(l, mid, 2*idx) & query(mid+1, r, 2*idx+1));
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    build(0, n-1, 1);
    while (q--) {
        char op;
        cin >> op;
        if (op == 'U') {
            int x, val;
            cin >> x >> val;
            x--;
            update(x, val, 1);
        } else {
            int x, y, val;
            cin >> x >> y >> val;
            x--; y--;
            cout << (val & query(x, y, 1)) << "\n";
        }
    }
}