#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[1000005], arr2[1000005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> q;
    
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    for (int i=0; i<n/2; i++) {
        // Smallest largest
        if (i == n/2 - 1) {
            cout << arr[i] << " " << arr[n-i-1];
        } else {
            cout << arr[i] << " " << arr[n-i-1] << " ";
        }
        
    }
    if (n%2 == 1) {
        cout << " " << arr[n/2] << endl;
    } else {
        cout << endl;
    }

    for (int i=0; i<n-(n%2); i+=2) {
        cout << "BS";
    }
    if (n%2 == 1) {
        cout << "E" << endl;
    } else {
        cout << endl;
    }
}