#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 3005;
int arr[MM][MM], ans = 0;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            cin >> arr[i][j];
        }
    }
    int d, cur, nxt;
    for (cur = 1, nxt = 2; nxt <= k; cur = nxt, nxt *= 1.5) {
        d = nxt - cur;
        for (int i=0; i<n-nxt+1; i++) {
            for (int j=0; j<=i; j++) {
                arr[i][j] = max(arr[i][j], max(arr[i+d][j], arr[i+d][j+d]) );
            }
        }
    }
    d = k-cur;
    for (int i=0; i<n-k+1; i++) {
        for (int j=0; j<=i; j++) {
            ans += max(arr[i][j], max(arr[i+d][j], arr[i+d][j+d]) );
        }
    }
    cout << ans << "\n";
}