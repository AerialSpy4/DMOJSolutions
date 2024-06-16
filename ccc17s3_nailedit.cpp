#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl "\n"

// Frequency of a plank length
int freq[2005];

// Frequency of a long plank / board length...
int lengths[4005];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        freq[temp]++;
    }

    // Lengths of boards (2 pieces)

    for (int i=1; i<=2000; i++) { // pieces of length i
        for (int j=i; j<=2000; j++) { // pieces of length j
            if (i == j) {
                // Since both pieces have same len, # of ways you can make i+j increases by floor(freq[i]/2) = freq[i/2]
                // Ex. freq 1, lengths += 0. freq 3, lengths += 1 (1 complete pair). freq 2, lengths += 1 (1 complete pair)
                lengths[i+j] += freq[i]/2;
            } else {
                // i and j must go together to make a pair, so take the minmum to find the # of complete pairs
                lengths[i+j] += min(freq[i], freq[j]);
            }
        }
    }

    // Find the maximum length of the fence.

    int maxn = 0;
    int ways = 0;

    for (int i=2; i<=4000; i++) {
        int num = lengths[i];
        if (num > maxn) {
            // There is a longer fence... update it!
            maxn = num;
            ways = 1;
        } else if (num == maxn) {
            // There's another way to make the longest fence... increase the number of ways.
            ways++;
        }
    }

    cout << maxn << " " << ways << endl;
}