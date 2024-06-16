#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define endl "\n"

bool solve(int m, int x, int y) {
    if (m == 1) {
        if ((y == 0 && x >= 1 && x <= 3) || (x == 2 && y == 1)) {
            return true;
        } else {
            return false;
        }
    }

    int power = pow(5, m-1);
    int nx = floor(x/power), ny = floor(y/power);
    if ((ny == 0 && nx >= 1 && nx <= 3) || (nx == 2 && ny == 1)) {
        return true;
    } else if ((ny == 1 && (nx == 1 || nx == 3)) || (nx == 2 && ny == 2)) {
        return solve(m-1, x%power, y%power);
    } else {
        return false;
    }
}

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int m, x, y;
        cin >> m >> x >> y;
        if (solve(m, x, y)) {
            cout << "crystal" << endl;
        } else {
            cout << "empty" << endl;
        }
    }
}