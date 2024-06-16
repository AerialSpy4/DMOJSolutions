#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int g;
    cin >> g;

    int p;
    cin >> p;

    set<int> available;

    for (int i=0; i<g; i++) {
        available.insert(g-i);
    }

    for (int i=0; i<p; i++) {
        int temp;
        cin >> temp;
        temp = g-temp;
        if (available.upper_bound(temp) != available.end()) {
            available.erase(*available.upper_bound(temp));
        } else {
            cout << i << endl;
            return 0;
        }
    }
    cout << p << endl;
}