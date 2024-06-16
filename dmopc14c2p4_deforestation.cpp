#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;
const int INF = 2e9;

#define endl "\n"

int arr[1000005], psa[1000005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    psa[0] = 0;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
        psa[i+1] = psa[i]+arr[i];
    }

    int q;
    cin >> q;

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << psa[b+1] - psa[a] << endl;
    }
}