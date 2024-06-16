#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int lo = 1, hi = 2e9;
    while (true) {
        int mid = (lo+hi)/2;
        cout << mid << endl;
        string op; cin >> op;
        if (op == "OK") {
            break;
        } else if (op == "SINKS") {
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
}