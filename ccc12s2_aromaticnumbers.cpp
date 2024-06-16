#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    unordered_map<char, int> ranking;
    ranking['I'] = 1;
    ranking['V'] = 5;
    ranking['X'] = 10;
    ranking['L'] = 50;
    ranking['C'] = 100;
    ranking['D'] = 500;
    ranking['M'] = 1000;

    // 2-3+20-45+10

    string s;
    cin >> s;

    vector<pair<int, char>> nums;
    for (int i=0; i<s.size(); i+=2) {
        nums.push_back({(int)(s[i])-'0', s[i+1]});
    }

    int ans = 0;

    for (int i=0; i<nums.size(); i++) {
        if (ranking[nums[i].second] < ranking[nums[i+1].second]) {
            ans -= nums[i].first * ranking[nums[i].second];
        } else {
            ans += nums[i].first * ranking[nums[i].second];
        }
    }

    cout << ans << endl;
}