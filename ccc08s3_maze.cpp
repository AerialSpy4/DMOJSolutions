#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define endl "\n"

int r, c;
vector<pair<int, int>> pluss = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<pair<int, int>> minuss = {{0, 1}, {0, -1}};
vector<pair<int, int>> bar = {{1, 0}, {-1, 0}};

bool inbound(int x, int y) {
    if (x < r && y < c && x >= 0 && y >= 0) {
        return true;
    } else {
        return false;
    }
}

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int tt=0; tt<t; tt++) {
        cin >> r >> c;

        char grid[r][c];

        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                cin >> grid[i][j];
            }
        }

        int visited[50][50] = {false}, distances[50][50] = {0};
        visited[0][0] = true;

        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty()) {
            auto node = q.front(); q.pop();
            int x = node.first, y = node.second;
            if (grid[x][y] == '+') {
                for (auto direction : pluss) {
                    int a = direction.first, b = direction.second;
                    if (inbound(x+a, y+b) && grid[x+a][y+b] != '*' && !visited[x+a][y+b]) {
                        q.push({x+a, y+b});
                        visited[x+a][y+b] = true;
                        distances[x+a][y+b] = distances[x][y]+1;
                    }
                }
            } else if (grid[x][y] == '-') {
                for (auto direction : minuss) {
                    int a = direction.first, b = direction.second;
                    if (inbound(x+a, y+b) && grid[x+a][y+b] != '*' && !visited[x+a][y+b]) {
                        q.push({x+a, y+b});
                        visited[x+a][y+b] = true;
                        distances[x+a][y+b] = distances[x][y]+1;
                    }
                }
            } else if (grid[x][y] == '|') {
                for (auto direction : bar) {
                    int a = direction.first, b = direction.second;
                    if (inbound(x+a, y+b) && grid[x+a][y+b] != '*' && !visited[x+a][y+b]) {
                        q.push({x+a, y+b});
                        visited[x+a][y+b] = true;
                        distances[x+a][y+b] = distances[x][y]+1;
                    }
                }
            }
        }

        if (visited[r-1][c-1]) {
            cout << distances[r-1][c-1]+1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
}