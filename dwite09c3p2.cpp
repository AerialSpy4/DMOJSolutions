#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    vector<int> fibonacci = {0, 1};
    while (fibonacci[fibonacci.size()-1] <= 1e9) {
        fibonacci.push_back(fibonacci[fibonacci.size()-1]+fibonacci[fibonacci.size()-2]);
    }

    for (int t=0; t<5; t++) {
        int n;
        cin >> n;
        int x = upper_bound(fibonacci.begin(), fibonacci.end(), n) - fibonacci.begin();
        if (abs(fibonacci[x]-n) <= abs(n-fibonacci[x-1])) {
            cout << fibonacci[x] << endl;
        } else {
            cout << fibonacci[x-1] << endl;
        }
    }
}