#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    unordered_map<int, int> squares;
    squares[99] = 77;
    squares[90] = 48;
    squares[54] = 19;
    squares[9] = 34;
    squares[40] = 64;
    squares[67] = 86;

    int curpos = 1;

    while (true) {
        int x; 
        cin >> x;

        if (x == 0) {
            cout << "You Quit!" << endl;
            return 0;
        }

        if (curpos+x > 100) {
            cout << "You are now on square " << curpos << endl;
            continue;
        }

        curpos += x;
        if (curpos == 100) {
            cout << "You are now on square " << curpos << endl;
            cout << "You Win!" << endl;
            break;
        } else if (squares.count(curpos)) {
            curpos = squares[curpos];
            cout << "You are now on square " << curpos << endl;
        } else {
            cout << "You are now on square " << curpos << endl;
        }
    }
}