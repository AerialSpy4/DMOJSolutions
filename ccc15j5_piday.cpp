#include <bits/stdc++.h>
using namespace std;

int memo[255][255][255], minval;
bool ready[255][255][255];

int n, k;
int solve(int curk, int preval, int total) {
    if (ready[curk][preval][total]) return memo[curk][preval][total];
    if (total == n && curk == k) return 1;
    int cnt = 0;
    if (curk == 0) {
        for (int i=preval; total+i<=minval; i++) {
            cnt += solve(curk+1, i, total+i);
        }
    } else {
        for (int i=preval; i+total <= n; i++) {
            int cursolve = solve(curk+1, i, total+i);
            cnt += cursolve;
        }
    }
    memo[curk][preval][total] = cnt;
    ready[curk][preval][total] = true;
    return cnt;
}

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    minval = n/k;
    cout << solve(0, 1, 0);
}