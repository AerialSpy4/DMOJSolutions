#include <bits/stdc++.h>
using namespace std;
const int MM = 1e3+5;
int aval[MM], bval[MM], score[MM][MM];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Get longest uncommon ??? subsequence of wins and losses, whose numbers must respect the requirements
    int n;
    cin >> n;
    string a; cin >> a;
    for (int i=0; i<n; i++) {
        cin >> aval[i];
    }
    string b; cin >> b;
    for (int i=0; i<n; i++) {
        cin >> bval[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i-1] == 'W' && b[j-1] == 'L' && aval[i-1] > bval[j-1] || b[j-1] == 'W' && a[i-1] == 'L' && bval[j-1] > aval[i-1]) {
                score[i][j] = max(score[i][j-1], max(score[i-1][j], score[i-1][j-1] + aval[i-1] + bval[j-1]));
            } else {
                score[i][j] = max(score[i][j-1], score[i-1][j]);
            }
        }

    }
    cout << score[n][n] << "\n";
}