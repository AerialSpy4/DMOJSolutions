#include <bits/stdc++.h>
using namespace std;

const int MM = 1e6+5;
int arr[MM];
unordered_map<int, vector<int>> indices;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
        indices[arr[i]].push_back(i+1);
    }

    for (int qq=0; qq<q; qq++) {
        int l, r, x;
        cin >> l >> r >> x;
        bool factorsfound = false;
        for (int i=1; i*i<x; i++) {
            if (x%i == 0) {
                if (upper_bound(indices[i].begin(), indices[i].end(), r)-lower_bound(indices[i].begin(), indices[i].end(), l) > 0 && 
                    upper_bound(indices[x/i].begin(), indices[x/i].end(), r)-lower_bound(indices[x/i].begin(), indices[x/i].end(), l) > 0) {
                    factorsfound = true;
                    break;
                }
            }
        }
        if (factorsfound) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}