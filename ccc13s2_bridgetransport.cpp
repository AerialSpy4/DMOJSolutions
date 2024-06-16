#pragma GCC optimize("Ofast")
#pragma GCC optimization("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int weights[100005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int w, n;
    cin >> w >> n;

    for (int i=0; i<n; i++) {
        cin >> weights[i];
    }

    if (weights[0] > w) {
        cout << 0 << endl;
        return 0;
    } else if (weights[0] + weights[1] > w) {
        cout << 1 << endl;
        return 0;
    } else if (weights[0]+weights[1] + weights[2] > w) {
        cout << 2 << endl;
        return 0;
    }

    for (int i=0; i<=n-4; i++) {
        if (weights[i]+weights[i+1]+weights[i+2]+weights[i+3] > w) {
            cout << i+3 << endl;
            return 0;
        }
    }

    cout << n << endl;
}