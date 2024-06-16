#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int arr[MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    set<int> vals;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
        auto it = vals.lower_bound(arr[i]);
        if (it != vals.end()) {
            vals.erase(*it);
            vals.insert(arr[i]);
        } else {
            vals.insert(arr[i]);
        }
    }
    cout << vals.size() << "\n";
}