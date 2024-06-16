#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[100005], psa[100005];
unordered_map<int, vector<int>> indices;

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k, q;
    cin >> n >> k >> q;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
        psa[i+1] = psa[i] + arr[i];
        indices[arr[i]].push_back(i);
    }

    for (int qq=0; qq<q; qq++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        x--; y--;

        bool afound = (upper_bound(indices[a].begin(), indices[a].end(), y) - lower_bound(indices[a].begin(), indices[a].end(), x) >= 1);
        bool bfound = (upper_bound(indices[b].begin(), indices[b].end(), y) - lower_bound(indices[b].begin(), indices[b].end(), x) >= 1);

        if (psa[y+1]-psa[x] > k && afound && bfound) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}