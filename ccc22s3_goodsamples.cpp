#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 1e6 + 5;
int notes[maxn];

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    if (k < n) {
        cout << -1 << endl;
        return 0;
    }

    k -= n;
    int prev = 0;
    int next;

    for (int i=1; i<=n; i++) {
        int limit = min(m-1, i-1);
        if (k >= limit) {
            next = prev < m ? prev+1 : 1;
            k -= limit;
        } else {
            next = max(notes[i-k-1], 1LL);
            k = 0;
        }
        notes[i] = next;
        prev = next;
    }

    if (k > 0) {
        cout << -1 << endl;
        return 0;
    }

    for (int i=1; i<=n; i++) {
        cout << notes[i] << " ";
    }
}