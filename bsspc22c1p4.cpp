#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[200005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // Try pie without removing
    // Then remove maximum in that range and then pie again

    int execspied = 0, time = 0;
    int maxval = 0, maxindex = 0;

    for (int i=0; i<n; i++) {
        time += arr[i];
        if (arr[i] > maxval) {
            maxval = arr[i];
            maxindex = i;
        }
        if (time > t) {
            break;
        } else {
            execspied++;
        }
    }

    execspied = 0, time = 0;

    for (int i=0; i<n; i++) {
        if (i != maxindex) {
            time += arr[i];
        } else {
            continue;
        }
        
        if (time > t) {
            break;
        } else {
            execspied++;
        }
    }

    cout << execspied << endl;
}