#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    
    int x=0, y=0;

    while (true) {
        int a, b;
        cin >> a >> b;
        if (!a && !b) {
            break;
        }
        x += a; y += b;
        if (x > r) x = r;
        if (y > c) y = c;
        if (x < 0) x = 0;
        if (y < 0) y = 0;

        cout << x << " " << y << endl;
    }
}