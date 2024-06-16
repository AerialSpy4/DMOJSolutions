#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
// #define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    if ((n-45)%90) {
        cout << "Rip Bob!" << endl;
    } else {
        cout << "Let's go Bob!" << endl;
    }
}
