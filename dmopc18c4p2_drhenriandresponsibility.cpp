#include <bits/stdc++.h>
using namespace std;
const int MM = 705;
int arr[MM]; bool dp[300005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, total = 0;
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    int half = total / 2;
    dp[0] = true;
    for (int i=1; i<=N; i++) {
        for (int j=0; j<=half; j++) {
            if (dp[j]) dp[j+arr[i]] = true;
        }
    }
    int ans = 0;
    for (int i=0; i<=half; i++) {
        if (dp[i]) ans = i;
    }
    cout << total - 2*ans<< '\n';
}