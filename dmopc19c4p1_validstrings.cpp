#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tc=0; tc<t; ++tc) {
        string s;
        cin >> s;
        int n = s.size();
        int open = 0, closed = 0;
        bool passed = true;
        for (auto c : s) {
            if (c == '(') open++;
            else if (c == ')') closed++;
            if (closed > open) {
                passed = false;
            }
        }
        if (closed != open) passed = false;
        cout << (passed ? "YES" : "NO") << "\n";
    }
}