#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> nums;

    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        nums.push_back(s);
    }

    sort(nums.begin(), nums.end(), [](string a, string b) {
        return a+b > b+a;
    });

    for (auto i : nums) {
        cout << i;
    }
    cout << endl;
}