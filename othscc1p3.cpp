#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

const int MM = 1e6+5;
int arr[MM];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, d;
    cin >> n >> d;

    int streak = 1, maxstreak = 1;
    int ans = 1;
    cin >> arr[0];

    for (int i=1; i<n; i++) {
        cin >> arr[i];
        if (abs(arr[i] - arr[i-1]) <= d) {
            streak++;
        } else {
            ans++;
            maxstreak = max(streak, maxstreak);
            streak = 1;
        }
    }

    maxstreak = max(maxstreak, streak);

    cout << ans << endl << maxstreak << endl;
}