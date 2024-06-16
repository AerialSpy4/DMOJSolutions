#pragma GCC optimize("Ofast")
#pragma GCC optimization("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MM = 1e6+5;
int diff[100005], psa[100005];
int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int stations, troops, waves;
    cin >> stations >> troops >> waves;
    for (int wave=0; wave<waves; wave++) {
        int s, f, k;
        cin >> s >> f >> k;
        diff[s-1]+= k;
        diff[f] -= k;
    }
    int ans = 0;
    for (int i=1; i<=stations; i++) {
        psa[i] = psa[i-1] + diff[i-1];
        if (psa[i] < troops) {
            ans++;
        }
    }
    cout << ans << endl;
}