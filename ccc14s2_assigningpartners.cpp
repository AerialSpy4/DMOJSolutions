#include <bits/stdc++.h>
using namespace std;

string a[35], b[35];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }

    unordered_map<string, string> partnering;

    bool ans = true;

    for (int i=0; i<n; i++) {
        if (a[i] == b[i] || (partnering.count(a[i]) && a[i] != partnering[b[i]]) || (partnering.count(b[i]) && partnering[a[i]] != b[i])) {
            ans = false;
            break;
        }

        partnering[a[i]] = b[i];
        partnering[b[i]] = a[i];
    }

    if (ans) {
        cout << "good" << endl;
    } else {
        cout << "bad" << endl;
    }
}