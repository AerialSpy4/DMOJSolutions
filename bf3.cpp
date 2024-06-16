#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;
const int INF = numeric_limits<int>::max();

#define endl "\n"

bool prime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i=2; i*i<=x; i++) {
        if (x%i == 0) {
            return false;
        }
    }
    return true;
}

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int i=n;
    while (true) {
        if (prime(i)) {
            cout << i << endl;
            return 0;
        }
        i++;
    }
}