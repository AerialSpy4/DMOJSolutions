#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int MM = 3e5+5;
int a[MM], b[MM];
vector<array<int, 3>> events;
vector<pair<char, pair<int, int>>> ansl, ansr;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    for (int j=0; j<n; j++) {
        cin >> b[j];
    }

    int prev = b[0];
    int cnt = 1;

    for (int i=1; i<n; i++) {
        if (prev == b[i]) {
            cnt++;
        } else {
            events.push_back({prev, i-cnt, i-1});
            prev = b[i];
            cnt = 1;
        }
    }

    events.push_back({prev, n-cnt, n-1});

    int curevent = 0;
    for (int i=0; i<n; i++) {
        if (events[curevent][0] == a[i]) {
            if (events[curevent][1] < i) {
                ansl.push_back({'L', {events[curevent][1], i}});
            } if (events[curevent][2] > i) {
                ansr.push_back({'R', {i, events[curevent][2]}});
            }
            curevent++;
        }
    }

    if (curevent != events.size()) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << ansl.size() + ansr.size() << endl;
    for (auto i : ansl) {
        cout << i.first << " " << i.second.first << " " << i.second.second << endl;
    }

    for (int i=ansr.size()-1; i>=0; i--) {
        cout << ansr[i].first << " " << ansr[i].second.first << " " << ansr[i].second.second << endl;
    }
}