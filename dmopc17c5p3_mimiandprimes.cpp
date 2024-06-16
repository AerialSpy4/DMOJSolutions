#include <bits/stdc++.h>
using namespace std;

int arr[100005];
#define endl "\n"
#define int long long

int primefactor(int x) {
     int i=2;
     int largest = 1;
     while (x != 1) {
          if (i*i > x) {
               return x;
          }
          while (x%i == 0) {
               x /= i;
          }
          largest = i;
          ++i;
     }
     return largest;
}

signed main() {
     cin.sync_with_stdio(0);
     cin.tie(0);

     int n;
     cin >> n;

     int g;
     cin >> g;
     for (int i=1; i<n; i++) {
          int temp; cin >> temp;
          g = __gcd(g, temp);
     }

     int ans = primefactor(g);
     if (ans == 1) {
          cout << "DNE" << endl;
     } else {
          cout << ans << endl;
     }
}