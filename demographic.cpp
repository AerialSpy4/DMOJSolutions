#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int arr[300005];

int32_t main() {
    int n;
    scan(n);

    for (int i=0; i<n; i++) {
        scan(arr[i]);
    }

    sort(arr, arr+n);

    int q;
    cin >> q;

    while (q--) {
        int a, b;
        scan(a); scan(b);
        cout << upper_bound(arr, arr+n, b) - lower_bound(arr, arr+n, a) << endl;
    }
}