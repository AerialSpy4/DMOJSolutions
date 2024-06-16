#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;

    for (int i=0; i<=c/a; i++) {
        for (int j=0; j<=c/b; j++) {
            if (i*a + j*b <= c && i*a+j*b > ans) {
                ans = i*a+j*b;
            }
        }
    }

    cout << ans << endl;
}