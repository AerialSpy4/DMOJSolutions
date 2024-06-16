#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
int arr[MM];
multiset<int> mult;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        mult.insert(arr[i]);
    }
    int prev = *mult.begin();
    mult.erase(mult.begin());
    vector<int> ans;
    ans.push_back(prev);
    for (int i=1; i<n; i++) {
        if (mult.lower_bound(m-prev) == mult.end()) {
            cout << -1 << '\n';
            return 0;
        }
        int item = *mult.lower_bound(m - prev);
        ans.push_back(item);
        mult.erase(mult.lower_bound(m-prev));
        prev = item;
    }
    for (auto i : ans) {
        cout << i << " ";
    }
}