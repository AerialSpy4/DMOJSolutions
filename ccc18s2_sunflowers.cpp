#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define endl "\n"

int arr[105][105], copyarr[105][105];

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    // Check, rotate, check rotate, ...

    for (int rr=0; rr<4; rr++) {
        // Check
        bool passed = true;

        for (int i=0; i<n; i++) {
            for (int j=0; j<n-1; j++) {
                if (arr[i][j+1] <= arr[i][j]) {
                    passed = false;
                    break;
                }
            }
        }

        for (int i=0; i<n-1; i++) {
            for (int j=0; j<n; j++) {
                if (arr[i+1][j] <= arr[i][j]) {
                    passed = false;
                    break;
                }
            }
        }

        if (passed) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
            return 0;
        }

        // Rotate        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                copyarr[i][j] = arr[j][n-1-i];
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                arr[i][j] = copyarr[i][j];
            }
        }
    }
}