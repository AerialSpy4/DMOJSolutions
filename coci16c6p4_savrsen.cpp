#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 1e7+5;
int ans[MM];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A, B;
    cin >> A >> B;
    for (int i=1; i<=B; i++) {
        for (int j=(A/i)*i; j<=(B/i)*i; j+=i) {
            if (j >= A && i != j) ans[j] += i;
        }
    }
    int fin = 0;
    for (int i=A; i<=B; i++) {
        fin += abs(i-ans[i]);
    }
    cout << fin << '\n';
}