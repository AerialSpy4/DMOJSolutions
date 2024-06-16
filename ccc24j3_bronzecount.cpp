#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    map<int, int> nums;

    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        nums[temp]++;
    }

    int limit = nums.size();
    int curcount = 0;
    for (auto p : nums) {
        int a = p.first, b = p.second;
        curcount++;
        if (curcount == limit-2) {
            cout << a << " " << b << endl;
            break;
        }
    }
}