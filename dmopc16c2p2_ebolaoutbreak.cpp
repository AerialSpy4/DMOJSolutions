#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define endl "\n"

int p[100005], rk[100005];

int find_set(int d) {
    if (p[d] != d) {
        p[d] = find_set(p[d]);
    }
    return p[d];
}

void unite(int x, int y) {
    if (rk[x] > rk[y]) {
        p[y] = x;
    } else {
        p[x] = y;
        if (rk[x] == rk[y]) {
            rk[y]++;
        }
    }
}

void link(int x, int y) {
    unite(find_set(x), find_set(y));
}

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        p[i] = i;
        rk[i] = 0;
    }
    for (int i=0; i<m; i++) {
        int o;
        cin >> o;

        int first; cin >> first;

        for (int j=0; j<o-1; j++) {
            int temp; cin >> temp;
            if (find_set(first) != find_set(temp)) {
                link(first, temp);
            }
        }
    }

    vector<int> ans;

    for (int i=1; i<=n; i++) {
        if (find_set(i) == find_set(1)) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;

    for (auto i : ans) {
        cout << i << " ";
    }
}