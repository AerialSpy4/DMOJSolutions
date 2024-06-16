#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int arr[1005], lis[1005];

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // Get the longest increasing subsequence sum
    lis[0] = arr[0];
    int ans = arr[0];
    for (int i=1; i<n; i++) {
        lis[i] = arr[i];
        for (int j=i-1; j>=0; j--) {
            if (arr[i] > arr[j]) {
                lis[i] = max(lis[i], lis[j]+arr[i]);
                ans = max(ans, lis[i]);
            }
        }
    }

    cout << ans << endl;

    // for(int i=0; i<n; i++) {
    //     cout << lis[i] << " ";
    // }
}