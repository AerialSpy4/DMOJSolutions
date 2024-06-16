#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;
const int INF = numeric_limits<int>::max();

#define endl "\n"

int arr[105];
int groups[105];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if (m > n) {
        cout << "NE" << endl;
        return 0;
    }

    int ans = 0;

    for (int i=0; i<m; i++) {
        cin >> arr[i];
        if (arr[i] < 4) {
            cout << "NE" << endl;
            return 0;
        }
        groups[i] = arr[i]/4;
    }

    // GO through ROUNDS

    sort(groups, groups+m);

    int fulltables = 0;

    for (int x=0; x<100005; x++) {
        for (int i=0; i<m; i++) {
            if (groups[i] > 0) {
                fulltables++;
                groups[i]--;
            }
        }
    }

    if (fulltables >= n) {
        cout << "DA" << endl;
    } else {
        cout << "NE" << endl;
    }
}