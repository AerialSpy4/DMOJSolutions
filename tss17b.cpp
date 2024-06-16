#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

#define int long long

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> distances;

    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        distances.push_back(x*x + y*y);
    }

    sort(distances.begin(), distances.end());

    for (int i=0; i<q; i++) {
        int r;
        cin >> r;
        cout << upper_bound(distances.begin(), distances.end(), r*r) - distances.begin() << endl;
    }
}