#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_map<int, int> a, b;
    for (int i=1; i<=n; i++) {
        cout << i << " " << i << "\n" << flush;
        int x, y;
        cin >> x >> y;
        if (b.count(x)) {
            cout << i << " " << b[x] << "\n" << flush;
            int d;
            cin >> d >> d;
            return 0;
        }
        a[x] = i;
        if (a.count(y)) {
            cout << a[y] << " " << i << "\n" << flush;
            int d;
            cin >> d >> d;
            return 0;
        }
        b[y] = i;
    }
}