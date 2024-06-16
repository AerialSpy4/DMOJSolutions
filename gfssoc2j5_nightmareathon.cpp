#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
int arr[MM];
unordered_map<int, vector<int>> freq;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        freq[arr[i]].push_back(i+1);
    }
    for (int tc=0; tc<q; tc++) {
        int l, r;
        cin >> l >> r;
        int rating=0, episodes=0;
        for (int i=10; i>0; --i) {
            int newfreq = freq[i].size() - (upper_bound(freq[i].begin(), freq[i].end(), r)-lower_bound(freq[i].begin(), freq[i].end(), l));
            if (newfreq != 0) {
                cout << i << " " << newfreq << "\n";
                break;
            }
        }
    }
}