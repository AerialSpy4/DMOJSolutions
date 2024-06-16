#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, q, bit[255][255][255], grid[255][255][255];
void update(int x, int y, int z, int v) {
    for (int i=x; i<=n; i+=i&-i) {
        for (int j=y; j<=n; j+=j&-j) {
            for (int k=z; k<=n; k+=k&-k) {
                bit[i][j][k] += v;
            }
        }
    }
}
int query(int x, int y, int z) {
    int ans = 0;
    for (int i=x; i>0; i-=i&-i) {
        for (int j=y; j>0; j-=j&-j) {
            for (int k=z; k>0; k-=k&-k) {
                ans += bit[i][j][k];
            }
        }
    }
    return ans;
}
void solve() {
    cin >> n >> q;
    int finalsum = 0;
    for (int i=0; i<q; i++) {
        char op;
        cin >> op;
        if (op == 'C') {
            int x, y, z, l;
            cin >> x >> y >> z >> l;
            update(x, y, z, l-grid[x][y][z]);
            grid[x][y][z] = l;
        } else {
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            int pie1 = query(x2, y2, z2) - query(x1-1, y2, z2) - query(x2, y1-1, z2) + query(x1-1, y1-1, z2);
            int pie2 = query(x2, y2, z1-1) - query(x1-1, y2, z1-1) - query(x2, y1-1, z1-1) + query(x1-1, y1-1, z1-1);
            int ans = pie1 - pie2;
            finalsum += ans;
        }
    }
    cout << finalsum << "\n";
}
signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    solve();
}