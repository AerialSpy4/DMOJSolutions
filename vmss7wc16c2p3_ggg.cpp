#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int a[MM], b[MM], dp[MM], pos[MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int M;
    cin >> M;
    for (int j=1; j<=M; j++) {
        cin >> b[j];
        if (pos[b[j]] != 0) {
            dp[j] = pos[b[j]];
        }
    }
    set<int> vals;
    for (int i=1; i<=M; i++) {
        if (dp[i] == 0) continue;
        auto it = vals.lower_bound(dp[i]);
        if (it != vals.end()) {
            vals.erase(*it);
            vals.insert(dp[i]);
        } else {
            vals.insert(dp[i]);
        }
    }
    cout << vals.size() << "\n";
}