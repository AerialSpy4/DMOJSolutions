#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int a[200005], b[200005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int cnt = 0;

    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (a[i]) cnt++;
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
        if (b[i]) cnt++;
    }

    cnt *= 3;

    for (int i=0; i<n; i++) {
        if (a[i] && b[i] && i%2 == 0) {
            cnt -= 2;
        }
    }

    for (int i=0; i<n-1; i++) {
        if (a[i] && a[i+1]) {
            cnt -= 2;
        }

        if (b[i] && b[i+1]) {
            cnt -= 2;
        }
    }

    cout << cnt << endl;
}