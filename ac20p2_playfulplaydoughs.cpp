#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define int long long
#define endl "\n"

int arr[100005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    unordered_map<int, int> freq;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    for (int qq=0; qq<q; qq++) {
        int type, x;
        cin >> type >> x;

        if (type == 1) {
            freq[x/2] += freq[x];
            freq[(x+1)/2] += freq[x];
            freq[x] = 0;
        } else {
            cout << freq[x] << endl;
        }
    }
}