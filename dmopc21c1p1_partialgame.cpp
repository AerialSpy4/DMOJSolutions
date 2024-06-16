#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 2e5+5;
int arr[MM];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int duke = 0, alice = 0;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        if (arr[i] & 1) {
            alice += arr[i]/2 + 1;
        } else {
            duke += arr[i]/2;
        }
    }
    if (alice >= duke) {
        cout << "Alice" << "\n";
    } else {
        cout << "Duke" << "\n";
    }
}