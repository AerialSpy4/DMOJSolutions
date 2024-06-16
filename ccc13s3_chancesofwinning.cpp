#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t, g;
    cin >> t >> g;

    set<pair<int, int>> gamepairs = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};

    array<int, 5> points = {0, 0, 0, 0, 0};

    for (int i=0; i<g; i++) {
        int a, b, sa, sb;
        cin >> a >> b >> sa >> sb;
        gamepairs.erase({a, b});
        if (sa > sb) {
            points[a] += 3;
        } else if (sb > sa) {
            points[b] += 3;
        } else {
            points[a]++; points[b]++;
        }
    }

    vector<array<int, 5>> scores;
    scores.push_back(points);

    for (auto g : gamepairs) {
        int a = g.first, b = g.second;
        vector<array<int, 5>> temp;
        for (auto score : scores) {
            array<int, 5> temp1(score);
            temp1[a] += 3;
            temp.push_back(temp1);

            array<int, 5> temp2(score);
            temp2[b] += 3;
            temp.push_back(temp2);

            array<int, 5> temp3(score);
            temp3[a]++; temp3[b]++;
            temp.push_back(temp3);
        }
        scores = temp;
    }

    int ans = 0;

    for (auto score : scores) {
        int maxval = 0, cnt = 0;
        for (int i=1; i<=4; i++) {
            if (score[i] > maxval) {
                maxval = score[i];
                cnt = 1;
            } else if (score[i] == maxval) {
                cnt++;
            }
        }
        if (cnt == 1 && maxval == score[t]) {
            ans++;
        }
    }

    cout << ans << endl;
}