// SEGMENT TREE !!! yay

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

const int MM = 2e5+5;

struct node { int l, r, v, ind;} seg[4*MM];

int a[MM]; char op;

void build(int l, int r, int idx){
	seg[idx].l = l; seg[idx].r = r;
	if(l == r) {
		seg[idx].v = a[l];
        seg[idx].ind = l;
		return;
	}
	int mid = (l + r)/2;
	build(l, mid, 2*idx);  build(mid+1, r, 2*idx+1);

    if (seg[2*idx].v > seg[2*idx+1].v) {
        seg[idx].v = seg[2*idx+1].v;
        seg[idx].ind = seg[2*idx+1].ind;
    } else {
        seg[idx].v = seg[2*idx].v;
        seg[idx].ind = seg[2*idx].ind;
    }
}

void update(int pos, int val, int idx){
	// Case: Root node
	if(seg[idx].l == seg[idx].r){
		seg[idx].v = val;
		return;
	}

	// Case: NOT root node
	
	int mid = (seg[idx].l + seg[idx].r)/2;
	
	if (pos <= mid) {
		update(pos, val, 2*idx);
	} else {
		update(pos, val, 2*idx + 1);
	}

	if (seg[2*idx].v > seg[2*idx+1].v) {
        seg[idx].v = seg[2*idx+1].v;
        seg[idx].ind = seg[2*idx+1].ind;
    } else {
        seg[idx].v = seg[2*idx].v;
        seg[idx].ind = seg[2*idx].ind;
    }
}

pair<int,int> query(int l, int r, int idx) {
    if(seg[idx].l == l && seg[idx].r == r) {
		return {seg[idx].v, seg[idx].ind};
	}
	int mid = (seg[idx].l + seg[idx].r)/2;
	if(r <= mid) {
		return query(l, r, 2*idx);
	}
	if(l > mid) {
		return query(l, r, 2*idx+1);
	}
	pair<int, int> val1 = query(l, mid, 2*idx), val2 = query(mid+1, r, 2*idx+1);
	if (val1 > val2) {
		return val2;
	} else {
		return val1;
	}
}

signed main(){
	cin.sync_with_stdio(0); cin.tie(0);
	
    int n, q;
    cin >> n >> q;

    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    build(0, n-1, 1);

    for (int i=0; i<q; i++) {
        char op; int x, y;
        cin >> op >> x >> y;
        if (op == 'U') {
            x--;
            update(x, y, 1);
        } else {
            x--; y--;
            cout << query(x, y, 1).first << " " << query(x, y, 1).second + 1 << endl;
        }
        
    }
}