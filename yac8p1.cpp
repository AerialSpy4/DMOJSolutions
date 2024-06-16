#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
int arr[1000005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int premax = 0, ans = 0;

    for (int i=1; i<=n; i++) {
        cin >> arr[i];
        premax = max(premax, arr[i]);
        if (premax > i || arr[i] != i) {
            ans++;
        }
    }

    cout << ans << endl;
}

