#include <bits/stdc++.h>
using namespace std;

const int MM = 1e6+5;
int dp[MM], dp2[MM];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, w;
    cin >> n >> w;

    for (int i=1; i<=n; i++) {
        int p1, v1, p2, v2, p3, v3;
        cin >> p1 >> v1 >> p2 >> v2 >> p3 >> v3;
        copy(dp2, dp2+w, dp);

        for (int j=1; j<=w; j++) {
            if (j-p1 >= 0) dp2[j] = max(dp2[j], v1 + dp[j-p1]);
            if (j-p2 >= 0) dp2[j] = max(dp2[j], v2 + dp[j-p2]);
            if (j-p3 >= 0) dp2[j] = max(dp2[j], v3 + dp[j-p3]);
        }
    }

    cout << dp2[w] << "\n";
}