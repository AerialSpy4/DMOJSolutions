#include <bits/stdc++.h>
using namespace std;

int rows[5000005], columns[5000005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    for (int i=0; i<k; i++) {
        char op; int num;
        cin >> op >> num;

        if (op == 'R') {
            rows[num-1]++;
        } else {
            columns[num-1]++;
        }
    }

    int ans = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            ans += (rows[i] + columns[j]) % 2;
        }
    }

    cout << ans << endl;
}