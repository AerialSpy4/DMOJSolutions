#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

#define int long long

int diff[3005][3005];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, mintint;
    cin >> n >> mintint;

    map<int, int> compressx, compressy, revx, revy;
    vector<pair<int, int>> xcords, ycords;
    vector<array<int, 5>> events;
    map<int, bool> inx, iny;

    for (int i=0; i<n; i++) {
        int x1, y1, x2, y2, t;
        cin >> x1 >> y1 >> x2 >> y2 >> t;

        events.push_back({x1, y1, x2, y2, t});
        if (!inx.count(x1)) {
            xcords.push_back({x1, t});
            inx[x1] = true;
        } if (!inx.count(x2)) {
            xcords.push_back({x2, t});
            inx[x2] = true;
        }

        if (!iny.count(y1)) {
            ycords.push_back({y1, t});
            iny[y1] = true;
        } if (!iny.count(y2)) {
            ycords.push_back({y2, t});
            iny[y2] = true;
        }
    }

    int counter = 1;

    sort(xcords.begin(), xcords.end());
    sort(ycords.begin(), ycords.end());

    for (auto i : xcords) {
        compressx[i.first] = counter;
        revx[counter] = i.first;
        counter++;
    }

    counter = 1;

    for (auto i : ycords) {
        compressy[i.first] = counter;
        revy[counter] = i.first;
        counter++;
    }

    // Run difference array
    
    for (auto event : events) {
        int r1 = event[0], c1 = event[1], r2 = event[2], c2 = event[3], t = event[4];
        diff[compressx[r1]][compressy[c1]] += t;
        diff[compressx[r1]][compressy[c2]] -= t;
        diff[compressx[r2]][compressy[c1]] -= t;
        diff[compressx[r2]][compressy[c2]] += t;
    }

    int ans = 0, anscnt = 0;
    for (int i=1; i<=compressx.size(); i++) {
        for (int j=1; j<=compressy.size(); j++) {
            diff[i][j] += diff[i][j-1]+diff[i-1][j]-diff[i-1][j-1];
            if (diff[i][j] >= mintint) {
                ans += abs(revx[i]-revx[i+1]) * abs(revy[j]-revy[j+1]);
                anscnt++;
            }
        }
    }

    // for (int i=1; i<=compressx.size(); i++) {
    //     for (int j=1; j<=compressy.size(); j++) {
    //         cout << diff[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << ans << endl;
}