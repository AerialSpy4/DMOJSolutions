#include <bits/stdc++.h>
using namespace std;
vector<int> dp(5005), backup(5005);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s, backs = "";
    cin >> s;
    for (int i=n-1; i>=0; i--) backs += s[i];
    // Answer: Total length - LCS
    int mv = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (s[i-1] == backs[j-1]) {
                dp[j] = backup[j-1]+1;
            } else {
                dp[j] = max(dp[j-1], backup[j]);
            }
        }
        backup = dp;
    }
    cout << n-dp[n] << "\n";
}