#include <bits/stdc++.h>
using namespace std;

int arr[505][505];

int main() {
    int n, k;
    cin >> n >> k;
    k--;

    int curnum = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<k; j++) {
            arr[i][j] = curnum++;
        }
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        ans += curnum;
        arr[i][k] = curnum++;
    }

    for (int i=0; i<n; i++) {
        for (int j=k; j<n; j++) {
            arr[i][j] = curnum++;
        }
    }

    cout << ans << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}