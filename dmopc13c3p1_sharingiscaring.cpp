#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<string>> ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int p, q;
        cin >> p >> q;
        string s;
        getline(cin, s);
        getline(cin, s);
        ans[q].push_back(s);
    }
    int Y;
    cin >> Y;
    for (auto i : ans[Y]) {
        cout << i << '\n';
    }
}
