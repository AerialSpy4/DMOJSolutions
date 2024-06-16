#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define endl "\n"

int grid[3005][3005], psa1[3005][3005], psa2[3005][3005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    while (true) {
        int r, c, x;
        cin >> r >> c >> x;

        if (!r && !c && !x) {
            break;
        }

        grid[r-1][c-1] += x;
    }

    // Construct PSA

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            psa1[i][j] = psa1[i-1][j] + psa1[i][j-1] - psa1[i-1][j-1] + ((i+j)%2 == 0) * grid[i-1][j-1];
            psa2[i][j] = psa2[i-1][j] + psa2[i][j-1] - psa2[i-1][j-1] + ((i+j)%2 == 1) * grid[i-1][j-1];
        }
    }

    while (true) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (!x1 && !y1 && !x2 && !y2) {
            break;
        }

        int firstsum = psa1[x2][y2] - psa1[x1-1][y2] - psa1[x2][y1-1] + psa1[x1-1][y1-1];
        int secondsum = psa2[x2][y2] - psa2[x1-1][y2] - psa2[x2][y1-1] + psa2[x1-1][y1-1];

        if ((x1+y1)%2 == 0) {
            cout << firstsum - secondsum << endl;
        } else {
            cout << secondsum - firstsum << endl;
        }
    }
}