#include <bits/stdc++.h>
using namespace std;
const int MM = 755;
bool existing[MM][MM];
int p[MM], rk[MM];
double dist(int x1, int y1, int x2, int y2) {
    return 1.0 * sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
int fs(int d) {
    return (d == p[d] ? p[d] : p[d] = fs(p[d]));
}
void unite(int x, int y) {
    x = fs(x); y = fs(y);
    if (rk[x] > rk[y]) {
        p[y] = x;
    } else {
        p[x] = y;
        if (rk[x] == rk[y]) {
            rk[y]++;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i<=n; i++) p[i] = i;
    vector<pair<int, int>> points;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        points.push_back({a, b});
    }
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        existing[a][b] = true;
        if (fs(a) != fs(b)) unite(a, b);
    }
    vector<pair<double, pair<int, int>>> edges;
    for (int i=0; i<points.size(); i++) {
        int x1 = points[i].first, y1 = points[i].second;
        for (int j=i+1; j<points.size(); j++) {
            int x2 = points[j].first, y2 = points[j].second;
            if (!existing[i+1][j+1]) {
                existing[i+1][j+1] = true;
                edges.push_back({1.0 * dist(x1, y1, x2, y2), {i+1, j+1}});
            }
        }
    }
    sort(edges.begin(), edges.end());
    vector<pair<int, int>> ans;
    double total = 0;
    for (auto edge : edges) {
        double d = edge.first; int a = edge.second.first, b = edge.second.second;
        if (fs(a) != fs(b)) {
            unite(a, b);
            ans.push_back({a, b});
            total += d;
        }
    }
    cout << fixed << setprecision(2) << total << "\n";
    for (auto i : ans) {
        cout << i.first << " " << i.second << "\n";
    }
}