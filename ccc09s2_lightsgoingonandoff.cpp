#include <bits/stdc++.h>
using namespace std;
int lights[35][10], nums[35];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c;
    cin >> r >> c;
    for (int i=0; i<r; i++) {
        int bin_num = 0;
        for (int j=0; j<c; j++) {
            cin >> lights[i][j];
            bin_num += lights[i][j] << (c-j-1);
        }
        nums[i] = bin_num;
    }
    // Process every possibility
    set<int> poss[r];
    poss[0].insert(nums[0]);
    for (int i=1; i<r; i++) {
        poss[i].insert(nums[i]);
        for (auto j : poss[i-1]) {
            poss[i].insert(nums[i]^j);
        }
    }
    cout << poss[r-1].size() << '\n';
}
