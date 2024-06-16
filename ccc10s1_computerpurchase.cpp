#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;
const int INF = 2e9;

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 0) {
        return 0;
    }

    vector<pair<int, string>> test;

    for (int i=0; i<n; i++) {
        string s; int a, b, c;
        cin >> s >> a >> b >> c;
        test.push_back({2*a+3*b+c, s});
    }

    sort(test.begin(), test.end(), [](pair<int, string> a, pair<int, string> b){
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first > b.first;
        }
    });

    if (test.size() > 1) {
        cout << test[0].second << endl << test[1].second << endl;
    } else {
        cout << test[0].second << endl;
    }
    
}