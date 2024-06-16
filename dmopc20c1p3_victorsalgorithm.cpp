#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 5e5+5;
int arr[MM];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int maxval = -2e9, maxindex = 0;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        if (arr[i] > maxval) {
            maxindex = i;
            maxval = arr[i];
        }
    }

    int ans = 0;
    // Make each element greater than or equal to than the previous one
    for (int i=1; i<maxindex; i++) {
        if (arr[i] < arr[i-1]) {
            ans += arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }
    }
    // Make each element greater than or equal to the next one
    for (int i=n-2; i>maxindex; i--) {
        if (arr[i] < arr[i+1]) {
            ans += arr[i+1]-arr[i];
            arr[i] = arr[i+1];
        }
    }
    cout << ans << "\n";
}