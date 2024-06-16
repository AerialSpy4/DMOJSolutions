#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    set< array<int, 6> > store;

    for (int i=0; i<n; i++) {
        array<int, 6> test, test2, test3, test4, test5, test6;
        for (int j=0; j<6; j++) {
            cin >> test[j];
            test2[(j+1)%6] = test[j];
            test3[(j+2)%6] = test[j];
            test4[(j+3)%6] = test[j];
            test5[(j+4)%6] = test[j];
            test6[(j+5)%6] = test[j];
        }
        if (store.count(test)) {
            cout << "Twin snowflakes found." << "\n";
            return 0;
        } else {
            reverse(test.begin(), test.end());
            if (store.count(test)) {
                cout << "Twin snowflakes found." << "\n";
                return 0;
            }
            store.insert(test);
            store.insert(test2);
            store.insert(test3);
            store.insert(test4);
            store.insert(test5);
            store.insert(test6);
        }
    }
    cout << "No two snowflakes are alike." << "\n";
}