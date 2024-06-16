#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> points;

    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        points.push_back({a, b});
    }

    points.push_back(points[0]);

    int up = 0;
    int dp = 0;

    for (int i=0; i<n; i++) {
        up += points[i].first * points[i+1].second;
        dp += points[i].second * points[i+1].first;
    }

    cout << ceil(0.5 * abs(up - dp)) << endl;
}