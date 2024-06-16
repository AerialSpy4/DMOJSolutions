#include <bits/stdc++.h>
using namespace std;
const int MM = 105;
int arr[MM], mincost=2e9;
vector<array<int, 3>> pigs;
vector<array<int, 4>> ac;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        pigs.push_back({s, t, c});
    }
    for (int i=0; i<m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ac.push_back({a, b, c, d});
    }
    // Brute force air conditioners
    // Maybe use binary nums to represent states
    int curstate = 0;
    while (curstate <= 1024) {
        int curcost = 0;
        fill(arr, arr+100, 0);
        for (int k=0; k<m; k++) {
            if (curstate & 1 << k) {
                auto [a, b, p, c] = ac[k];
                curcost += c;
                for (int i=a; i<=b; i++) {
                    arr[i] += p;
                }
            }
        }
        bool valid = true;
        // Check each pig
        for (auto [x, y, z] : pigs) {
            for (int i=x; i<=y; i++) {
                if (arr[i] < z) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            mincost = min(mincost, curcost);
        }
        curstate++;
    }
    cout << mincost << '\n';
}
