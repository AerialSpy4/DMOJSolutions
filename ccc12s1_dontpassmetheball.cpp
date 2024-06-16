#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // n-1 choose 3 = (n-1)! / (n-4!)(3!)

    cout << (n-1) * (n-2) * (n-3) / 6 << endl;
}