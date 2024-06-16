#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr+n);

    for (int i=0; i<m; i++) {
        int temp;
        cin >> temp;
        cout << n-(lower_bound(arr, arr+n, temp)-arr) << endl;
    }
}