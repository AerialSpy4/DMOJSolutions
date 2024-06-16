#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;
const int INF = numeric_limits<int>::max();

#define endl "\n"

int arr[200005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int maxn = 0;

    for (int i=0; i<n; i++) {
        // Find largest index of element that doesn't pass K range. 
        // Last element that's <= than arr[i]+k
        // [ First element > arr[i]+k ] - 1

        int el = arr[i];
        int range = upper_bound(arr, arr+n, el+k)-arr - 1;
        maxn = max(maxn, range-i+1);
    }

    cout << maxn << endl;
}