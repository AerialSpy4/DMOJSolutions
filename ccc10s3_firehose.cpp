#include <bits/stdc++.h>
using namespace std;

int h, k;
int location[1005];
const int circ = 1e6;

/* 
    Function that, given the maximum length a firehose can be, calculates the minimum number of hydrants 
    needed for a range x using brute force
*/
int get_hydrants(int x) {
    // Ans is the minimum 
    int ans = h;

    // This is the range of the firehose. 2*x since x will be the answer, but both left and right works. 
    int d = 2*x;

    // Loop through all the starting houses since we dont know where each hose starts and ends
    for (int i=0; i<h; i++) {
        // This is the starting house
        int cnt = 1;
        int start = location[i];
        for (int j=1; j<h; j++) {
            int cur;
            if (i+j < h) {
                cur = location[i+j];
            } else {
                // Case for lapping
                cur = location[i+j-h] + circ;
            }

            if (cur - start > d) {
                ++cnt;
                start = cur;
            }
        }
        ans = min(ans, cnt);
    }
    return ans;
}

int main() {
    cin >> h;

    for (int i=0; i<h; i++) {
        cin >> location[i];
    }

    // Sort to get up for Binary Search
    sort(location, location+h);

    cin >> k;


    // Binary Search
    int lo = 0; int hi = circ/2;
    int ans = hi;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        int hydrants = get_hydrants(mid);
        if (hydrants > k) {
            // This mid value doesnt work so we know all values below it doesn't work. 
            lo = mid+1;
        } else {
            // Update ans since this mid value works. But can we go lower?
            hi = mid-1;            
            ans = min(ans, mid);
        }
    }

    cout << ans << endl;
}