#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;
const int INF = numeric_limits<int>::max();

#define endl "\n"

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int, string> numbers;
    unordered_map<string, int> revnumbers;

    for (int i=0; i<n; i++) {
        string name; int number;
        cin >> name >> number;

        numbers[number] = name;
        revnumbers[name] = number;
    }

    int m;
    cin >> m;

    unordered_map<string, int> freq;

    for (int i=0; i<m; i++) {
        int s;
        cin >> s;
        freq[numbers[s]]++;
    }

    int maxfreq = 0;
    string maxname = "";

    for (auto i : freq) {
        if (i.second > maxfreq) {
            maxname = i.first;
            maxfreq = i.second;
        } else if (i.second == maxfreq) {
            if (revnumbers[i.first] < revnumbers[maxname]) {
                maxname = i.first;
                maxfreq = i.second;
            }
        }
    }

    cout << maxname << endl;
}