#include <bits/stdc++.h>
using namespace std;

const int MM = 2e6+5;
#define endl "\n"

bool sieve[MM];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    sieve[0] = true;
    sieve[1] = true;

    for (int i=2; i<=MM-5; i++) {
        if (!sieve[i]) {
            for (int j=2*i; j<=MM-5; j+=i) {
                sieve[j] = true;
            }
        }
    }

    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int x;
        cin >> x;

        x *= 2;

        for (int i=0; i<x; i++) {
            if (!sieve[i] && !sieve[x-i]) {
                cout << i << " " << x-i << endl;
                break;
            }
        }
    }
}