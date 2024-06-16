#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

char grid[105][105];
int visited[105][105], distances[105][105];
bool camera[105][105];

vector<pair<int, int>> dot = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int r, c;

bool inbound(int x, int y) {
    if (x >= 0 && y >= 0 && x < r && y < c) return true;
    return false;
}

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    pair<int, int> start;

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                start = {i, j};
            }
        }
    }

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (grid[i][j] == 'C') {
                camera[i][j] = true;
                // Up
                for (int y=j; y>=0; y--) {
                    if (grid[i][y] == 'W') {
                        break;
                    } else if (grid[i][y] == '.' || grid[i][y] == 'S') {
                        camera[i][y] = true;
                    }
                }

                // Down
                for (int y=j; y<c; y++) {
                    if (grid[i][y] == 'W') {
                        break;
                    } else if (grid[i][y] == '.' || grid[i][y] == 'S') {
                        camera[i][y] = true;
                    }
                }

                // Left
                for (int x=i; x>=0; x--) {
                    if (grid[x][j] == 'W') {
                        break;
                    } else if (grid[x][j] == '.' || grid[x][j] == 'S') {
                        camera[x][j] = true;
                    }
                }

                // Right
                for (int x=i; x<r; x++) {
                    if (grid[x][j] == 'W') {
                        break;
                    } else if (grid[x][j] == '.' || grid[x][j] == 'S') {
                        camera[x][j] = true;
                    }
                }
            }
        }
    }

    deque<pair<int, int>> q;
    q.push_back(start);

    while (!q.empty()) {
        auto node = q.front(); q.pop_front();
        int x = node.first, y = node.second;
        if (grid[x][y] == '.' || grid[x][y] == 'S') {
            for (auto i : dot) {
                int a = i.first, b = i.second;
                if (inbound(x+a, y+b) && grid[x+a][y+b] == '.' && !visited[x+a][y+b] && !camera[x+a][y+b]) {
                    q.push_back({x+a, y+b});
                    visited[x+a][y+b] = true;
                    distances[x+a][y+b] = distances[x][y]+1;
                } else if (inbound(x+a, y+b) && grid[x+a][y+b] != 'W' && !visited[x+a][y+b] && !camera[x+a][y+b]) {
                    q.push_front({x+a, y+b});
                    visited[x+a][y+b] = true;
                    distances[x+a][y+b] = distances[x][y];
                }
            }
        } else if (grid[x][y] == 'L') {
            if (inbound(x, y-1) && grid[x][y-1] != 'W' && !visited[x][y-1]) {
                if (grid[x][y-1] == '.' && camera[x][y-1]) continue;
                else if (grid[x][y-1] == '.') {
                    q.push_back({x, y-1});
                    distances[x][y-1] = distances[x][y]+1;
                    visited[x][y-1] = true;
                } else {
                    q.push_front({x, y-1});
                    visited[x][y-1] = true;
                    distances[x][y-1] = distances[x][y];
                }
                
            }
        } else if (grid[x][y] == 'R') {
            if (inbound(x, y+1) && grid[x][y+1] != 'W' && !visited[x][y+1]) {
                if (grid[x][y+1] == '.' && camera[x][y+1]) continue;
                else if (grid[x][y+1] == '.') {
                    q.push_back({x, y+1});
                    distances[x][y+1] = distances[x][y]+1;
                    visited[x][y+1] = true;
                } else {
                    q.push_front({x, y+1});
                    visited[x][y+1] = true;
                    distances[x][y+1] = distances[x][y];
                }
            }
        } else if (grid[x][y] == 'U') {
            if (inbound(x-1, y) && grid[x-1][y] != 'W' && !visited[x-1][y]) {
                if (grid[x-1][y] == '.' && camera[x-1][y]) continue;
                else if (grid[x-1][y] == '.') {
                    q.push_back({x-1, y});
                    distances[x-1][y] = distances[x][y]+1;
                    visited[x-1][y] = true;
                } else {
                    q.push_front({x-1, y});
                    visited[x-1][y] = true;
                    distances[x-1][y] = distances[x][y];
                }
            }
        } else if (grid[x][y] == 'D') {
            if (inbound(x+1, y) && grid[x+1][y] != 'W' && !visited[x+1][y]) {
                if (grid[x+1][y] == '.' && camera[x+1][y]) continue;
                else if (grid[x+1][y] == '.') {
                    q.push_back({x+1, y});
                    distances[x+1][y] = distances[x][y]+1;
                    visited[x+1][y] = true;
                } else {
                    q.push_front({x+1, y});
                    visited[x+1][y] = true;
                    distances[x+1][y] = distances[x][y];
                }
            }
        }
    }

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (grid[i][j] == '.') {
                if (camera[start.first][start.second]) {
                    cout << -1 << endl;
                } else if (visited[i][j]) {
                    cout << distances[i][j] << endl;
                } else {
                    cout << -1 << endl;
                }
            }
        }
    }
}