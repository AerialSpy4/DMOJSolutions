#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int arr[MM], ans[MM];
bool vis[MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Find every cycle and offset every element
    int n; long long k;
    cin >> n >> k;
    for (int i=1; i<=n; ++i) {
        cin >> arr[i];
    }
    for (int i=1; i<=n; ++i) {
        int orig = i;
        if (vis[orig]) continue;
        int idx = arr[i];
        vis[i] = true;
        vector<int> cycle;
        cycle.push_back(i);
        while (idx != orig) {
            vis[idx] = true;
            cycle.push_back(idx);
            idx = arr[idx];
        }
        int adv = k%cycle.size()+cycle.size()-1;
        for (int j=0; j<cycle.size(); ++j) {
            ans[cycle[(j+adv)%cycle.size()]] = cycle[j];
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
}