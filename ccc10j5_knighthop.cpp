#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define endl "\n"

bool inbound(int x, int y) {
    if (x > 0 && y > 0 && y <= 8 && x <= 8) {
        return true;
    } else {
        return false;
    }
}

int distances[10][10];
bool visited[10][10];

vector<pair<int, int>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

int32_t main() {
    int x1, y1, x2, y2;
    scan(x1); scan(y1); scan(x2); scan(y2);

    queue<pair<int, int>> q;
    q.push({x1, y1});
    visited[x1][y1] = true;

    while (!q.empty()) {
        auto node = q.front(); q.pop();
        int x = node.first, y = node.second;
        for (auto direction : directions) {
            int a = direction.first, b = direction.second;
            if (inbound(x+a, y+b) && !visited[x+a][y+b]) {
                q.push({x+a, y+b});
                visited[x+a][y+b] = true;
                distances[x+a][y+b] = distances[x][y] + 1;
            }
        }
    }

    cout << distances[x2][y2] << endl;
}