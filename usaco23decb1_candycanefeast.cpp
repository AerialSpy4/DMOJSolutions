#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int cows[200005];
int canes[200005];

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> cows[i];
    }

    for (int i=0; i<m; i++) {
        cin >> canes[i];
    }

    for (int i=0; i<m; i++) {
        int eaten = 0;
        int noweaten = 0;
        for (int j=0; j<n; j++) {
            if (cows[j] > eaten && cows[j] <= canes[i]) {
                noweaten = eaten;
                eaten = cows[j];
                cows[j] += cows[j]-noweaten;
            } else if (cows[j] > eaten && cows[j] > canes[i]) {
                cows[j] += canes[i]-eaten;
                eaten = canes[i]+eaten;
            }
            if (eaten >= canes[i]) {
                break;
            }
        }
    }

    for (int i=0; i<n; i++) {
        cout << cows[i] << endl;
    }
}

