#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long double

double trianglearea(int x1, int y1, int x2, int y2, int x3, int y3) {
    return abs((x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3)) / 2.0;
}

bool pointintriangle(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3) {
    if (trianglearea(x1, y1, x2, y2, x, y)+trianglearea(x1, y1, x3, y3, x, y)+trianglearea(x2, y2, x3, y3, x, y) == trianglearea(x1, y1, x2, y2, x3, y3)) {
        return true;
    } else {
        return false;
    }
}


signed main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> points;

    for (int i=0; i<n; i++) {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        points.push_back({a, b, c, d, e, f});
    }

    for (int qq=0; qq<q; qq++) {
        int x, y;
        cin >> x >> y;

        int cnt = 0;
        for (auto point : points) {
            int a = point[0], b = point[1], c = point[2], d = point[3], e = point[4], f = point[5];

            int tx = x, ty = y;
            // Get x1 and y1 to be 0 aka a and b
            a -= point[0]; c -= point[0]; e -= point[0]; tx -= point[0];
            b -= point[1]; d -= point[1]; f -= point[1]; ty -= point[1];

            // Get y2 to be positive
            if (d < 0) {
                d = abs(d);
                ty = -ty;
            }

            // get x3 to be positive
            if (e < 0) {
                e = abs(e);
                tx = -tx;
            }

            // y = mx + b
            // y = -d/e x + d
            // y + x(d/e) = d

            if (! (tx < 0 || ty < 0 || ty + tx * (d/e) > d) ) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}