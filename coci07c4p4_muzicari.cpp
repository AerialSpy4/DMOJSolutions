#include <bits/stdc++.h>
using namespace std;
const int MM = 5005;
int arr[MM], dp[MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t >> n;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=t; j>=arr[i]; j--) {
            if (!dp[j] && dp[j-arr[i]]) {
                dp[j] = i;
            }
        }
    }
    int ptr;
    for (int i=t; i>=0; i--) {
        if (dp[i] != 0) {
            ptr = i;
            break;
        }
    }
    vector<int> group1, group2;
    unordered_map<int, bool> ing1;
    while (ptr != 0) {
        ing1[dp[ptr]] = true;
        group1.push_back(dp[ptr]);
        ptr -= arr[dp[ptr]];
    }
    int people[n+2];
    for (int i=1; i<=n; i++) {
        if (!ing1[i]) {
            people[i] = 2;
        } else {
            people[i] = 1;
        }
    }
    int g1time = 0, g2time = 0;
    for (int i=1; i<=n; i++) {
        if (people[i] == 1) {
            cout << g1time << " ";
            g1time += arr[i];
        } else {
            cout << g2time << " ";
            g2time += arr[i];
        }
    }
    cout << "\n";
}