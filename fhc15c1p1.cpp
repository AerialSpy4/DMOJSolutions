#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define endl "\n"

const int MM = 1e7+5;

bool sieve[MM];
int factors[MM];

int32_t main() {
    sieve[0] = true;
    sieve[1] = true;

    for (int i=2; i<MM; i++) {
        if (!sieve[i]) {
            factors[i]++;
            for (int j=2*i; j<MM; j+=i) {
                sieve[j] = true;
                factors[j]++;
            }
        }
    }

    int t;
    scan(t);

    // Sieve up to 1e7

    for (int tt=0; tt<t; tt++) {
        int a, b, k;
        scan(a); scan(b); scan(k);

        int ans = 0;

        for (int i=a; i<=b; i++) {
            if (factors[i] == k) {
                ans++;
            }
        }

        cout << "Case #" << tt+1 << ": " << ans << endl;
    }
}