#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<array<int, 4>> eventx, eventy;

    for (int i=0; i<n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // No negative coordinates
        x1 += 10000;
        y1 += 10000;
        x2 += 10000;
        y2 += 10000;
        eventy.push_back({y1, x1, x2, -1});
        eventy.push_back({y2, x1, x2, 1});

        eventx.push_back({x1, y1, y2, -1});
        eventx.push_back({x2, y1, y2, 1});
    }

    // -1 = enter, 1 = exit
    sort(eventx.begin(), eventx.end());
    sort(eventy.begin(), eventy.end());

    int cnt[20005] = {0};
    int ans = 0;

    for (auto event : eventx) {
        int x = event[0], y1 = event[1], y2 = event[2], v = event[3];
        if (v == -1) {
            for (int i=y1; i<y2; i++) {
                cnt[i]++;
                if (cnt[i] == 1) {
                    ans++;
                }
            }
        } else {
            for (int i=y1; i<y2; i++) {
                cnt[i]--;
                if (cnt[i] == 0) {
                    ans++;
                }
            }
        }
    }

    fill(cnt, cnt+20000, 0);

    for (auto event : eventy) {
        int x = event[0], y1 = event[1], y2 = event[2], v = event[3];
        if (v == -1) {
            for (int i=y1; i<y2; i++) {
                cnt[i]++;
                if (cnt[i] == 1) {
                    ans++;
                }
            }
        } else {
            for (int i=y1; i<y2; i++) {
                cnt[i]--;
                if (cnt[i] == 0) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}