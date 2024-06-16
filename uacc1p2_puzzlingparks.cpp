#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    if (n%4 == 2) {
        cout << n + n/2 - 2 << endl;
    } else if (n%2 == 0 || n%4 == 1) {
        cout << n + n/2 - 1 << endl;
    } else {
        cout << n + n/2 << endl;
    }
}
