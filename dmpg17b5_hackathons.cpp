#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int arr[MM], dp[MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> items;
    for (int i=0; i<n; i++) {
        int w, v;
        cin >> w >> v;
        arr[w] = max(arr[w], v);
    }
    for (int i=1; i<MM; i++) {
        dp[i] = max(dp[i-1], arr[i]);
    }
    int q;
    cin >> q;
    for (int i=0; i<q; i++) {
        int x;
        cin >> x;
        cout << dp[x] << "\n";
    }

}