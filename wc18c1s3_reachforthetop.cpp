#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int diff[MM], arr[MM], vis[MM], dist[MM];
set<int> items;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int h, j, n;
    cin >> h >> j >> n;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        diff[a]++;
        diff[b+1]--;
    }
    for (int i=1; i<=2*h; i++) {
        items.insert(i);
    }
    arr[0] = diff[0];
    for (int i=1; i<=h; i++) {
        arr[i] = arr[i-1] + diff[i];
        if (arr[i] != 0) {
            items.erase(*items.find(i));
        }
    }
    deque<int> q;
    q.push_back(0);
    while (!q.empty()) {
        int cur = q.front(); q.pop_front();
        if (cur >= h) {
            cout << dist[cur] << '\n';
            return 0;
        }
        vector<int> toerase;
        for (const int &it : items) {
            if (it >= cur) break;
            q.push_back(it);
            dist[it] = dist[cur]+1;
            toerase.push_back(it);
        }
        for (auto i : toerase) {
            items.erase(*items.find(i));
        }
        if (items.find(cur+j) != items.end()) {
            q.push_back(cur+j);
            items.erase(*items.find(cur+j));
            dist[cur+j] = dist[cur] + 1;
        }
    }
    cout << -1 << '\n';
}