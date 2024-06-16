#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int cnt = 0;

    for (int i=0; pow(i, 6) <= b; i++) {
        if (pow(i, 6) >= a) {
            cnt ++;
        }
    }

    cout << cnt << endl;
}