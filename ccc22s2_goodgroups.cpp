#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;
#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int x;
    cin >> x;

    unordered_map<string, unordered_map<string, bool>> same, different;

    for (int i=0; i<x; i++) {
        string a, b;
        cin >> a >> b;
        same[a][b] = true;
        same[b][a] = true;
    }

    int y;
    cin >> y;


    for (int i=0; i<y; i++) {
        string a, b;
        cin >> a >> b;

        different[a][b] = true;
        different[b][a] = true;
    }


    int g; cin >> g;
    int violated_d = 0, unviolated_s = 0;

    for (int gg=0; gg<g; gg++) {
        string a, b, c;
        cin >> a >> b >> c;

        // Different
        if (different[a][b]) violated_d++;
        if (different[a][c]) violated_d++;
        if (different[b][c]) violated_d++;

        // Same
        if (same[a][b]) unviolated_s++;
        if (same[a][c]) unviolated_s++;
        if (same[b][c]) unviolated_s++;
    }

    cout << violated_d + x - unviolated_s << endl;
}