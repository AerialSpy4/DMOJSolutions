#include <bits/stdc++.h>
using namespace std;
const int MM = 3e5+5;
string arr[MM];
int sizes[MM];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    for (int i=0; i<n; i++) {
        string cur;
        cin >> cur;
        ans += sizes[cur.size()];
        if (i >= k) {
            sizes[arr[i-k].size()]--;
        }
        sizes[cur.size()]++;
        arr[i] = cur;
    }
    cout << ans << "\n";
}