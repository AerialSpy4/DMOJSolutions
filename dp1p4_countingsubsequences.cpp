#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 1e5+5, MOD = 1e4+7;
map<char, int> pre;
int dp[MM];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    // for (int i=0; i<1000; i++) {
    //     s += "abcdefg";
    // }
    int n = s.size();
    dp[0] = 1;
    for (int i=1; i<=n; i++) {
        dp[i] = 2*dp[i-1];
        if (pre.count(s[i-1])) {
            dp[i] -= dp[pre[s[i-1]]];
        }
        pre[s[i-1]] = i-1;
        dp[i] %= MOD;
    }
    cout << (dp[n] + MOD - 1) % MOD << "\n";
    // for (int i=0; i<n; i++) {
    //     cout << dp[i] << "\n";
    // }
}