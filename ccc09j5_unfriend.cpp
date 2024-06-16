#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, ways[7] = {1, 1, 1, 1, 1, 1, 1};

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i=1; i<n; i++) {
        int temp;
        cin >> temp;
        ways[temp] *= ways[i]+1;
    }
    
    cout << ways[n];
}
