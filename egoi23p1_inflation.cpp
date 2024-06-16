#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 3e5+5;
int arr[MM];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, ans = 0;
    cin >> N;
    unordered_map<int, int> vals;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
        ans += arr[i];
        vals[arr[i]]++;
    }
    int Q;
    cin >> Q;
    int inf = 0;
    while (Q--) {
        string op;
        cin >> op;
        if (op == "INFLATION") {
            int x;
            cin >> x;
            inf += x;
            ans += N*x;
        } else {
            int x, y;
            cin >> x >> y;
            if (x != y) {
                ans -= vals[x-inf]*x;
                ans += vals[x-inf]*y;
                vals[y-inf] += vals[x-inf];
                vals[x-inf] = 0;
            }

        }
        cout << ans << '\n';
    }
}
