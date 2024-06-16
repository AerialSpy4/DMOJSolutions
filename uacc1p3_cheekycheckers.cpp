#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

char grid[8][8];

vector<pair<int, int>> directions = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

bool inbound(int x, int y) {
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        return true;
    } else {
        return false;
    }
}

int maxdist = 0;
int origx, origy;

void dfs(int cx, int cy, int px, int py, bool visited[8][8], int distances[8][8]) {
    maxdist = max(maxdist, distances[cx][cy]);
    for (auto direction : directions) {
        int a = direction.first; int b = direction.second;

        if (inbound(cx+2*a, cy+2*b) && grid[cx+a][cy+b] == 'B' && (grid[cx+2*a][cy+2*b] == '.' || (cx+2*a == origx && cy+2*b == origy)) && !visited[cx+a][cy+b]) {
            bool newvisited[8][8]; int newdistances[8][8];
            for (int i=0; i<8; i++) {
                for (int j=0; j<8; j++) {
                    newvisited[i][j] = visited[i][j];
                    newdistances[i][j] = distances[i][j];
                }
            }
            newvisited[cx+a][cy+b] = true;
            newdistances[cx+2*a][cy+2*b] = newdistances[cx][cy]+1;
            dfs(cx+2*a, cy+2*b, cx, cy, newvisited, newdistances);
        }
    }
}

signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (grid[i][j] != 'A') {
                continue;
            }

            bool v[8][8] = {0};
            int d[8][8] = {0};

            for (int x=0; x<8; x++) {
                for (int y=0; y<8; y++) {
                    d[x][y] = 0;
                }
            }
            
            origx = i;
            origy = j;
            dfs(i,j, -1, -1, v, d);

        }
    }

    cout << maxdist << endl;
}