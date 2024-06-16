#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int x;
        cin >> x;
        int binx = 0;
        vector<int> binary;
        for (int i=log2(x); i>=0; i--) {
            if (x >= (1 << i)) {
                x -= 1 << i;
                binary.push_back(1);
            } else {
                binary.push_back(0);
            }
        }
        int cnt = 0, ans = 0;
        for (auto i : binary) {
            if (i) ans += 1 << cnt;
            cnt++;
        }
        cout << ans << endl;
    }
}