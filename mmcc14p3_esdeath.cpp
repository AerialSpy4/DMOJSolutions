#include <bits/stdc++.h>
using namespace std;
const int MM = 5005;
vector<int> adj[MM];
vector<pair<int, int>> depths;
int p[MM], covered[MM];
void depth_dfs(int cur, int pre, int depth) {
    p[cur] = pre;
    depths.push_back({depth, cur});
    for (auto nxt : adj[cur]) {
        if (nxt != pre) {
            depth_dfs(nxt, cur, depth+1);
        }
    }
}
void cover_dfs(int cur, int pre, int target) {
    covered[cur] = true;
    if (target == 0) return;
    for (auto nxt : adj[cur]) {
        if (nxt != pre) {
            cover_dfs(nxt, cur, target-1);
        }
    }
}
bool check(int len, int lim) {
    int cnt = 0;
    memset(covered, 0, sizeof(covered));
    for (auto d : depths) {
        int node = d.second;
        if (covered[node]) continue;
        for (int i=0; i<len; i++) node = p[node];
        cnt++;
        cover_dfs(node, 0, len);
    }
    return (cnt <= lim);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    cin >> n >> s;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (s == n) {
        cout << 0 << "\n";
        return 0;
    }
    depth_dfs(1, 1, 0);
    sort(depths.begin(), depths.end(), greater<>());
    int lo = 1, hi = n-1, ans = n-1;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (check(mid, s)) {
            ans = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    cout << ans << "\n";
}