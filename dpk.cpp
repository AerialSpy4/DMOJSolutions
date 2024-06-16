#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
bool dp[MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> moves;
    for (int i=0; i<n; i++) {
        int temp; cin >> temp;
        moves.push_back(temp);
    }
    for (int i=1; i<=k; i++) {
        for (auto j : moves) {
            if (i-j >= 0 && !dp[i-j]) {
                dp[i] = true; break;
            }
        }
    }
    cout << (dp[k] ? "First" : "Second") << "\n";
}