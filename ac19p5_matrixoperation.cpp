#include <bits/stdc++.h>
using namespace std;
const int MM = 1505;
int arr[MM][MM], dp[MM][MM];
bool inbound(int x, int y, int n) {
    if (x < n && y < n && x >= 0 and y >= 0) return true;
    else return false;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int, 3>> increasing;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
            dp[i][j] = 1;
            increasing.push_back({arr[i][j], i, j});
        }
    }
    sort(increasing.begin(), increasing.end());
    int maxans = 0;
    for (auto i : increasing) {
        int val = i[0], x = i[1], y = i[2];
        int curans = 0;
        if (inbound(x-1, y, n) && arr[x-1][y] < arr[x][y]) {
            curans = max(curans, dp[x-1][y]);
        } if (inbound(x+1, y, n) && arr[x+1][y] < arr[x][y]) {
            curans = max(curans, dp[x+1][y]);
        } if (inbound(x, y-1, n) && arr[x][y-1] < arr[x][y]) {
            curans = max(curans, dp[x][y-1]);
        } if (inbound(x, y+1, n) && arr[x][y+1] < arr[x][y]) {
            curans = max(curans, dp[x][y+1]);
        }
        dp[x][y] = curans + 1;
        maxans = max(curans+1, maxans);
    }
    cout << maxans-1 << "\n";
}