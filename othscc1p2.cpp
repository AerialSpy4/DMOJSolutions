#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int totalsum = 0, maxnum = 0;

    for (int i=0; i<n; i++) {
        int temp; cin >> temp;
        totalsum += temp;
        maxnum = max(maxnum, temp);
    }

    cout << (totalsum-maxnum) / (n-1) << endl;
}