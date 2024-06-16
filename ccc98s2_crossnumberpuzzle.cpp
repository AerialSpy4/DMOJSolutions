#include <bits/stdc++.h>
using namespace std;

const int MM = 2e6+5;
#define endl "\n"

int sumofdivisors(int x) {
    int ans = 1;
    for (int i=2; i*i<=x; i++) {
        if (x%i == 0) {
            if (i == x/i) {
                ans += i;
            } else {
                ans += i;
                ans += x/i;
            }
        }
    }
    return ans;
}

int digitcubesum(int x) {
    string s = to_string(x);
    int ans = 0;
    for (char c : s) {
        ans += pow(((int)c-'0'), 3);
    }
    return ans;
}

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int i=1000; i<=9999; i++) {
        if (sumofdivisors(i) == i) {
            cout << i << " ";
        }
    }
    cout << endl;
    

    for (int i=100; i<=999; i++) {
        if (digitcubesum(i) == i) {
            cout << i << " ";
        }
    }

    cout << endl;
}