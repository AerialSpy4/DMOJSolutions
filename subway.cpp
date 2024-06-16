#include <bits/stdc++.h>
using namespace std;
const int MM = 50005;
vector<int> adj[MM];
int dist[MM], cnt[MM], dia, num;
void dfs(int cur, int pre) {
    cnt[cur] = 1;
    for (auto nxt : adj[cur]) {
        if (nxt != pre) {
            dfs(nxt, cur);
            if (dist[nxt] + dist[cur] + 1 > dia) {
                dia = dist[nxt] + dist[cur] + 1;
                num = cnt[cur] * cnt[nxt];
            } else if (dist[nxt] + dist[cur] + 1 == dia) {
                num += cnt[cur] * cnt[nxt];
            }
            if (dist[nxt] + 1 > dist[cur]) {
                dist[cur] = dist[nxt] + 1;
                cnt[cur] = cnt[nxt];
            } else if (dist[nxt] + 1 == dist[cur]) {
                cnt[cur] += cnt[nxt];
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i=0; i<N-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    cout << num << "\n";
}