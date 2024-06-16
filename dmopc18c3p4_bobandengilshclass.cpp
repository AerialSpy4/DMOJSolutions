#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 2e5+5;
vector<pair<int, int>> adj[MM];
int arr[MM], sz[MM], dist[MM], kids[MM];
void get_sz(int cur, int pre) {
    sz[cur] = kids[cur];
    for (auto [nxt, w] : adj[cur]) {
        if (nxt != pre) {
            get_sz(nxt, cur);
            sz[cur] += sz[nxt];
        }
    }
}
int centroid(int cur, int pre, int total) {
    for (auto [nxt, w] : adj[cur]) {
        if (nxt != pre && sz[nxt] * 2 > total) {
            return centroid(nxt, cur, total);
        }
    }
    return cur;
}
void dfs(int cur ,int pre) {
    for (auto [nxt, w] : adj[cur]) {
        if (nxt != pre) {
            dist[nxt] = dist[cur] + w;
            dfs(nxt, cur);
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K, N;
    cin >> K >> N;
    for (int i=1; i<=K; i++) {
        cin >> arr[i];
        kids[arr[i]]++;
    }
    for (int i=0; i<N-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    get_sz(1, -1);
    int c = centroid(1, -1, K);
    dfs(c, -1);
    int ans =  0;
    for (int i=1; i<=N; i++) {
        ans += dist[i] * kids[i];
    }
    cout << ans << '\n';
}