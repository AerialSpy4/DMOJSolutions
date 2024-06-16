#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9+7;
int dp[3005];

const int MM = 2e5+5;
int F[MM], I[MM];

int exp(int x, int y, int md){
    int ans = 1;
    x = x%md;
    while (y > 0) {
        if (y&1)
            ans = ans*x%md;
        y = y>>1;
        x = x*x%md;
    }
    return ans;
}

int choose(int n, int k) {
    if (k > n) return 0;
    return F[n] * I[k] % MOD * I[n - k] % MOD;
}

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    F[0] = 1, I[0] = 1;
    for (int i = 1; i < MM; i++) {
        F[i] = i * F[i - 1] % MOD;
        I[i] = exp(F[i], MOD - 2, MOD);
    }

    int r, c, x;
    cin >> r >> c >> x;
    int ans = 0;
    vector<pair<int, int>> blocks;
    for (int i=0; i<x; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        blocks.push_back({a, b});
    }
    blocks.push_back({r-1, c-1});
    sort(blocks.begin(), blocks.end());
    for (int i=0; i<=x; i++) {
        int r1 = blocks[i].first, c1 = blocks[i].second;
        int cursum = 0;
        dp[i] = choose(r1+c1, r1);
        for (int j=0; j<i; j++) {
            int r2 = blocks[j].first, c2 = blocks[j].second;
            if (c2<=c1) {
                dp[i] = (dp[i] - dp[j] * choose(r1+c1-r2-c2, r1-r2) % MOD + MOD) % MOD;
            }
        }
    }
    cout << dp[x] % MOD << "\n";
}
