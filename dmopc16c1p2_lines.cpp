#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int, unordered_map<int, bool>> mb;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<int, int>> lines;
    for (int i=0; i<N; i++) {
        int m, b;
        cin >> m >> b;
        lines.push_back({m, b});
        if (mb[m][b]) {
            cout << "Infinity" << '\n';
            return 0;
        }
        mb[m][b] = true;
    }
    int ans = 0;
    for (auto [m, b] : lines) {
        ans += lines.size() - mb[m].size();
    }
    cout << ans / 2 << '\n';
}