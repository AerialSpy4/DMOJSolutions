#include <bits/stdc++.h>
using namespace std;
const int MM = 55;
char grid[MM][MM];
int dist[MM][MM], vis[MM][MM];
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool inbound(int a, int b, int R, int C) {
    if (a >= 0 && b >= 0 && a < R && b < C) {
        return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int C, R;
        cin >> C >> R;
        pair<int, int> washroom, computer;
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                cin >> grid[i][j];
                if (grid[i][j] == 'C') {
                    computer = {i, j};
                } else if (grid[i][j] == 'W') {
                    washroom = {i, j};
                }
                dist[i][j] = 0; vis[i][j] = false;
            }
        }
        queue<pair<int, int>> q;
        q.push(computer);
        vis[computer.first][computer.second] = true;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (auto [a, b] : directions) {
                if (inbound(x+a, y+b, R, C) && !vis[x+a][y+b] && grid[x+a][y+b] != 'X') {
                    q.push({x+a, y+b});
                    vis[x+a][y+b] = true;
                    dist[x+a][y+b] = dist[x][y]+1;
                }
            }
        }
        if (dist[washroom.first][washroom.second] >= 60 || !vis[washroom.first][washroom.second]) {
            cout << "#notworth" << '\n';
        } else {
            cout << dist[washroom.first][washroom.second] << '\n';
        }
    }
}
