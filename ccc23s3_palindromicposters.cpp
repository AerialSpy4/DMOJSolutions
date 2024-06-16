#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;

#define endl "\n"

char grid[2005][2005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, r, c;
    cin >> n >> m >> r >> c;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            grid[i][j] = 'a';
        }
    }

    if (r < n && c < m) {
        for (int i=r; i<n-1; i++) {
            grid[i][m-1] = 'b';
        }

        for (int i=c; i<m-1; i++) {
            grid[n-1][i] = 'b';
        }

        grid[n-1][m-1] = 'c';
    } else if (r == n && c < m) {
        if ((m-c)%2 == 0) {
            for (int i=0; i<(m-c)/2; i++) {
                grid[0][i] = grid[0][m-1-i] = 'b';
            }
        } else if (m%2 == 1) {
            for (int i=0; i<(m-c)/2; i++) {
                grid[0][i] = grid[0][m-i-1] = 'b';
            }
            grid[0][m/2] = 'b';
        } else {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    } else if (r < n && c == m) {
        if ((n-r)%2 == 0) {
            for (int i=0; i<(n-r)/2; i++) {
                grid[i][0] = grid[n-1-i][0] = 'b';
            }
        } else if (n%2 == 1) {
            for (int i=0; i<(n-r)/2; i++) {
                grid[i][0] = grid[n-1-i][0] = 'b';
            }
            grid[n/2][0] = 'b';
        } else {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}