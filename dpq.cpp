#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
const int MM = 2e5+5;
struct node {int l, r, v;} seg[4*MM];
int heights[MM], arr[MM], dp[MM], n;
void build(int l, int r, int idx) {
	seg[idx].l = l; seg[idx].r = r;
	if (l == r) {
		// It's a root node
		seg[idx].v = dp[l];
		return;
	}

	int mid = (l+r)/2;
	build(l, mid, 2*idx);
	build(mid+1, r, 2*idx+1);
	seg[idx].v = max(seg[2*idx].v, seg[2*idx+1].v);
}
void update(int pos, int val, int idx) {
	if (seg[idx].l == seg[idx].r) {
		// Root node
		seg[idx].v = val;
		return;
	}
	int mid = (seg[idx].l + seg[idx].r)/2;

	if (pos <= mid) {
		update(pos, val, 2*idx);
	} else {
		update(pos, val, 2*idx+1);
	}
	seg[idx].v = max(seg[2*idx].v, seg[2*idx+1].v);
}
int query(int l, int r, int idx, int curval) {
	if(seg[idx].l == l && seg[idx].r == r) {
		return seg[idx].v;
	}

	int mid = (seg[idx].l + seg[idx].r)/2;
	if (r <= mid) {
		return query(l, r, 2*idx, curval);
	} else if (l > mid) {
		return query(l, r, 2*idx+1, curval);
	}
	return max(query(l, mid, 2*idx, curval), query(mid+1, r, 2*idx+1, curval));
}
signed main() {
    cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> heights[i];
	}
	for (int i=0; i<n; i++) {
		cin >> arr[i];
	}
	build(0, n-1, 1);
	update(heights[0], arr[0], 1);
	for (int i=1; i<n; i++) {
		update(heights[i], query(0, heights[i]-1, 1, 1)+arr[i], 1);
	}
	int ans = 0;
	for (int i=0; i<n; i++) {
		ans = max(ans, query(i, i, 1, 2e9));
	}
	cout << ans << endl;
}