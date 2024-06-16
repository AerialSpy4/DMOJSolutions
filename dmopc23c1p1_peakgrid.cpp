#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;

#define endl "\n"

int grid[2005][2005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int curnum = n*n;

    for (int i=0; i<k; i++) {
        grid[n-i-1][n-i-1] = curnum--;
    }

    for (int i=0; i<n; i++) {
        for (int j=n-k; j<n; j++) {
            if (grid[i][j] == 0) {
                grid[i][j] = curnum--;
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n-k; j++) {
            grid[i][j] = curnum--;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}