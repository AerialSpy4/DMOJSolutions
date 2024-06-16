#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    pair<long double, int> sci = {1.0000000000, 0};
    for (int i=2; i<=N; i++) {
        sci.first *= i;
        while (log10(sci.first) > 1) {
            sci.first /= 10;
            sci.second++;
        }
    }
    cout << setprecision(7) << sci.first << "e+" << sci.second << '\n';
}