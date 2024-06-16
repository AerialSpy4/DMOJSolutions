#include <bits/stdc++.h>
using namespace std;
const int MM = 105;
char arr[MM][MM], newarr[MM][MM];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '#') {
                newarr[i][j] = newarr[i+1][j] = newarr[i][j+1] = newarr[i+1][j+1] = '#';
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << (newarr[i][j] != '#' ? '.' : '#');
        }
        cout << '\n';
    }
}