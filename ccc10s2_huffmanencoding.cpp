#include <bits/stdc++.h>
using namespace std;

const int MM = 0;
#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    unordered_map<string, char> stoc;

    for (int i=0; i<k; i++) {
        char c; string s;
        cin >> c >> s;
        stoc[s] = c;
    }

    string seq;
    cin >> seq;

    queue<char> q;
    for (auto i : seq) {
        q.push(i);
    }

    while (!q.empty()) {
        string curstr = "";
        while (true) {
            curstr += q.front(); q.pop();
            if (stoc.count(curstr)) {
                cout << stoc[curstr];
                break;
            }
        }
    }
}