#include <bits/stdc++.h>
using namespace std;

// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
// char _;

#define endl "\n"

unordered_map<char, vector<int>> psa;

int32_t main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);

    for (int i=0; i<26; i++) {
        psa[i].push_back(0);
        for (int j=1; j<=s.size(); j++) {
            if (s.at(j-1) == 'a'+i) {
                psa[i].push_back(psa[i][j-1] + 1);
            } else {
                psa[i].push_back(psa[i][j-1]);
            }
            
        }
    }

    int q;
    cin >> q;

    for (int i=0; i<q; i++) {
        int a, b; char c;
        cin >> a >> b >> c;
        cout << psa[c-'a'][b] - psa[c-'a'][a-1] << endl;
    }
}