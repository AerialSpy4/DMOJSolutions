#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tt=0; tt<t; tt++) {
        int n;
        cin >> n;
        stack<int> top, branch;

        for (int i=0; i<n; i++) {
            int temp; cin >> temp;
            top.push(temp);
        }

        int cur = 1;

        bool passed = true;

        while (cur < n) {
            if (!top.empty() && top.top() == cur) {
                cur++;
                top.pop();
            } else if (!branch.empty() && branch.top() == cur) {
                cur++;
                branch.pop();
            } else if (!top.empty()) {
                branch.push(top.top());
                top.pop();
            } else {
                passed = false;
                break;
            }
        }

        if (passed) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
}