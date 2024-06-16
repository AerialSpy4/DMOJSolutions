#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MM = 200005;

int n, q, bit[MM], arr[MM];

void update(int p, int v) {
    for (int i=p; i<=n; i+=i&-i) {
        bit[i] += v;
    }
}

int query(int p) {
    int ans = 0;
    for (int i=p; i>0; i-=i&-i) {
        ans += bit[i];
    }
    return ans;
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i=0; i<n; i++) {
        cin >> arr[i+1];
        update(i+1, arr[i+1]);
    }

    for (int i=0; i<q; i++) {
        char op;
        cin >> op;

        if (op == 'S') {
            int l, r;
            cin >> l >> r;
            cout << query(r) - query(l-1) << endl;
        } else if (op == 'U') {
            int i, x; cin >> i >> x;
            update(i, x-arr[i]);
            arr[i] = x;
        }
    }
}