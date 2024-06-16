#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int orient(Point p1, Point p2, Point p3) {
    int det = (p2.x-p1.x) * (p3.y-p1.y) - (p3.x-p1.x)*(p2.y-p1.y);
    if (det == 0) {
        return 0;
    } else {
        return det > 0 ? 1 : -1;
    }
}

bool on_segment(Point p1, Point p2, Point p3) {
    return p3.x <= max(p1.x, p2.x) &&  p3.x >= min(p1.x, p2.x) && p3.y <= max(p1.y, p2.y) && p3.y >= min(p1.y, p2.y);
}

bool intersect(Point p1, Point p2, Point p3, Point p4) {
    int o1 = orient(p1, p2, p3);
    int o2 = orient(p1, p2, p4);
    int o3 = orient(p3, p4, p1);
    int o4 = orient(p3, p4, p2);

    if (o1 != o2 && o3 != o4) {
        return true;
    }

    if (o1 == 0 && on_segment(p1, p2, p3)) {
        return true;
    }
    if (o2 == 0 && on_segment(p1, p2, p4)) {
        return true;
    }
    if (o3 == 0 && on_segment(p3, p4, p1)) {
        return true;
    }
    if (o4 == 0 && on_segment(p3, p4, p2)) {
        return true;
    }
    return false;
}

int main() {
    // Geometry yay!!!

    cin.sync_with_stdio(0);
    cin.tie(0);

    Point p1, p2;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;

    int n;
    cin >> n;

    int cnt = 0;
    for (int i=0; i<n; i++) {
        int m;
        cin >> m;

        vector<Point> vp;
        for (int j=0; j<m; j++) {
            int x, y;
            cin >> x >> y;
            vp.push_back({x, y});
        }

        for (int j=0; j<m; j++) {
            int k = (j+1)%m;
            if (intersect(p1, p2, vp[j], vp[k])) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << endl;
}