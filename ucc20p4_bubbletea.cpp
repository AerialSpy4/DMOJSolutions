#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int arr[MM], dp[MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    for (int i=1; i<N; i++) {
        dp[i] = dp[i-1]+arr[i];
        if (i >= 1) {
            dp[i] = min(dp[i], int(dp[i-2]+min(arr[i], arr[i-1])*0.75+max(arr[i], arr[i-1])) ); 
        } if (i >= 2) {
            vector<int> vals = {arr[i], arr[i-1], arr[i-2]};
            sort(vals.begin(), vals.end());
            dp[i] = min(dp[i], dp[i-3]+int(vals[2]+vals[1]+vals[0]*0.5));
        }
    }
    cout << dp[N-1] << '\n';
}