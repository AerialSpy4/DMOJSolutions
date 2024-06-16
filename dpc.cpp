#include <bits/stdc++.h>
using namespace std;
int dp[3], pre[3];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (i == 0) {
            dp[0] = a; dp[1] = b; dp[2] = c;
        } else {
            dp[0] = max(pre[1], pre[2])+a;
            dp[1] = max(pre[0], pre[2])+b;
            dp[2] = max(pre[0], pre[1])+c;
        }
        swap(dp, pre);
    }
    cout << max(pre[0], max(pre[1], pre[2]));
}