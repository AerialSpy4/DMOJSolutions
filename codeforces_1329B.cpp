// -- Codeforces Problem 1329B --- //

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

signed main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int d, m;
        cin >> d >> m;
        
        int ans = 1;

        for (int i=0; i<32; i++) {
            if ((1<<i) > d) {
                break;
            }
            int cnt = min(d, (1LL << (i+1))-1) - (1LL << i) + 2;
            ans = ans * cnt % m;
        }

        cout << (ans+m-1) % m << endl;
    }
}