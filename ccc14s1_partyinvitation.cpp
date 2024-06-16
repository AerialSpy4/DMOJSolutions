#include <bits/stdc++.h>
using namespace std;

bool chosen[105];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int l, n;
    cin >> l >> n;

    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        int counter = 0;
        for (int j=0; j<l; j++) {
            if (!chosen[j] && counter%x == x-1) {
                chosen[j] = true;
                counter++;
            } else if (!chosen[j]) {
                counter++;
            }
        }
    }

    for (int i=0; i<l; i++) {
        if (!chosen[i]) {
            cout << i+1 << endl;
        }
    }
}
