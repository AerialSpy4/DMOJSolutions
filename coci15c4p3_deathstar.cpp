#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+5;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int ans = 0;
        for (int j=0; j<n; j++) {
            int x; cin >> x;
            ans |= x;
        }
        cout << ans << " ";
    }
}
