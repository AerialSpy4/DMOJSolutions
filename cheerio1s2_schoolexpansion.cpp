#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int, unordered_map<int, bool>> vis;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin >> n >> a >> b;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
    int complete = 0, cost=0;
    q.push({a+b, 1, 1});
    cost = 0;
    vis[1][1] = true;
    while (!q.empty()) {
        auto node = q.top(); q.pop();
        int x = node[1], y = node[2];
        cost += node[0];
        complete++;
        if (complete >= n) {
            break;
        }
        if (!vis[x+1][y]) {
            vis[x+1][y] = true;
            q.push({a*(x+1)+b*y, x+1, y});
        } if (!vis[x][y+1]) {
            vis[x][y+1] = true;
            q.push({a*x+b*(y+1), x, y+1});
        }
    }
    cout << cost << "\n";
}