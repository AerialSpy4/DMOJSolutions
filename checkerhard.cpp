#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MM = 3e3+1;
int bit[3005][3005], bit2[3005][3005], grid[3005][3005];
void update1(int r, int c, int v) {
    for (int i=r; i<=MM; i+=i&-i) {
        for (int j=c; j<=MM; j+=j&-j) {
            bit[i][j] += v;
        }
    }
}
void update2(int r, int c, int v) {
    for (int i=r; i<=MM; i+=i&-i) {
        for (int j=c; j<=MM; j+=j&-j) {
            bit2[i][j] += v;
        }
    }
}
int query1(int r, int c) {
    int ans = 0;
    for (int i=r; i>0; i-=i&-i) {
        for (int j=c; j>0; j-=j&-j) {
            ans += bit[i][j];
        }
    }
    return ans;
}
int query2(int r, int c) {
    int ans = 0;
    for (int i=r; i>0; i-=i&-i) {
        for (int j=c; j>0; j-=j&-j) {
            ans += bit2[i][j];
        }
    }
    return ans;
}
signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (true) {
        int op;
        cin >> op;
        if (op == 1){
            int r, c, x;
            cin >> r >> c >> x;
            if ((r+c)%2 == 0) {
                update1(r, c, x - grid[r][c]);
                grid[r][c] = x;
            } else {
                update2(r, c, x-grid[r][c]);
                grid[r][c] = x;
            }
        } else if (op == 2) {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            int result1 = query1(r2, c2) - query1(r1-1, c2) - query1(r2, c1-1) + query1(r1-1, c1-1);
            int result2 = query2(r2, c2) - query2(r1-1, c2) - query2(r2, c1-1) + query2(r1-1, c1-1);
            if ((r1+c1)%2 == 0) {
                cout << result1 - result2 << "\n";
            } else {
                cout << result2 - result1 << "\n";
            }
        } else if (op == 0) {
            break;
        }
    }
}