#include <bits/stdc++.h>
using namespace std;
unordered_map<int, set<int>> points;
vector<pair<int, int>> pointslist;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        points[a].insert(b);
        pointslist.push_back({a, b});
    }
    int ans = 0;
    for (int i=0; i<pointslist.size(); i++) {
        auto [x1, y1] = pointslist[i];
        for (int j=i+1; j<pointslist.size(); j++) {
            auto [x2, y2] = pointslist[j];
            if (x1 != x2 && y1 != y2 && points[x1].count(y2) && points[x2].count(y1)) {
                ans = max(abs(x2-x1) * abs(y2-y1), ans);
            }
        }
    }
    cout << ans << '\n';
}