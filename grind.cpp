#include <bits/stdc++.h>
using namespace std;
const int MM = 1e7+5;
int arr[MM], diff[MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        diff[a]++; diff[b]--;
    }
    for (int i=1; i<MM; i++) {
        arr[i] = arr[i-1]+diff[i-1];
    }
    cout << *(max_element(arr, arr+MM)) << '\n';
}
