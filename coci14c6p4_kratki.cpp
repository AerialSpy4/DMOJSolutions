#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int groups = ceil(1.0*n/k);
    if (groups > k) {
        cout << -1 << "\n";
    } else {
        // Increasing segments of k going down (ex. n = 9, k = 2, ans = 8 9 6 7 4 5 2 3 1)
        int largest = n;
        while (largest >= 1) {
            vector<int> toprint;
            for (int i=largest-k+1; i<=largest; i++) {
                if (i < 1) continue;
                cout << i << " ";
            }
            largest -= k;
        }
    }
}