#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;
const int INF = numeric_limits<int>::max();

vector<int> towers;

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int x;
        cin >> x;

        if (upper_bound(towers.begin(), towers.end(), x) == towers.end()) {
            towers.push_back(x);
        } else {
            towers[ upper_bound(towers.begin(), towers.end(), x)-towers.begin() ] = x;
        }
    }

    cout << towers.size() << endl;
}