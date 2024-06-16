#include <bits/stdc++.h>
using namespace std;

char arr[300005];

int main() {
    int n;
    cin >> n;

    vector<int> grouplens;




    int curlen = 0;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        if (arr[i] == '1') {
            curlen++;
        } else {
            if (curlen-i == 0) {
                grouplens.push_back(curlen-1);
            } else {
                grouplens.push_back((curlen-1)/2);
            }
            curlen = 0;
        }
    }
}