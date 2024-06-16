#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
const int MM = 1e4+5;

bool visited[MM][MM];
char grid[MM][MM];
int n, m;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool inbound(int x, int y) {
    if (x >= 0 && y >= 0 && x < n && y < m) {
        return true;
    } else {
        return false;
    }
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    int fx, fy;
    cin >> fx >> fy;
    queue<pair<int, int>> q;
    visited[fx][fy] = true;
    q.push({fx, fy});
    int s = 0, l = 0, m = 0;
    if (grid[fx][fy] == 'S') s++;
    else if (grid[fx][fy] == 'M') m++;
    else if (grid[fx][fy] == 'L') l++;
    while (!q.empty()) {
        pair<int, int> node = q.front(); q.pop();
        int x = node.first, y = node.second;

        for (auto direction : directions) {
            int a = direction.first, b = direction.second;
            if (inbound(x+a, y+b) && grid[x+a][y+b] != '*' && !visited[x+a][y+b]) {
                visited[x+a][y+b] = true;
                q.push({x+a, y+b});
                if (grid[x+a][y+b] == 'S') s++;
                else if (grid[x+a][y+b] == 'M') m++;
                else if (grid[x+a][y+b] == 'L') l++;
            }
        }
    }
    cout << s + 5*m + 10*l << endl;
}