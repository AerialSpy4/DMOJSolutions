#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // Set rows to positive, columns to negative, collisions means they must add to 0

    unordered_map<int, int> rvals, cvals;

    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        if (temp != -1) {
            rvals[i-temp]++;
        }
    }

    for (int i=0; i<m; i++) {
        int temp;
        cin >> temp;
        if (temp != -1) {
            cvals[i-temp]++;
        }
    }

    // cout << "RVALS" << endl;

    // for (auto i : rvals) {
    //     cout << i.first << " " << i.second << endl;
    // }

    // cout << "CVALS" << endl;

    // for (auto i : cvals) {
    //     cout << i.first << " " << i.second << endl;
    // }

    int collisions = 0;

    for (auto i : rvals) {
        int a = i.first, b = i.second;
        if (cvals[a] > 0 && rvals[a] > 0) {
            if (cvals[a] < rvals[a]) {
                collisions += cvals[a];
                rvals[a] -= cvals[a];
                cvals[a] = 0;
            } else {
                collisions += rvals[a];
                cvals[a] -= rvals[a];
                rvals[a] = 0;
            }
        }
    }

    cout << collisions << endl;
}