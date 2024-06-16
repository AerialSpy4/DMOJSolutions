#include <bits/stdc++.h>
using namespace std;
vector< pair<pair<string, string>, double> > edges;
unordered_map<string, double> vals;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string temp; cin >> temp;
    }
    for (int i=0; i<m; i++) {
        string a, b;
        double weight;
        cin >> a >> b >> weight;
        edges.push_back({{a, b}, weight});
    }
    vals["APPLES"] = 1;
    for (int i=0; i<50; i++) {
        for (auto e : edges) {
            vals[e.first.second] = max(vals[e.first.second], vals[e.first.first] * e.second);
        }   
    }    
    if (abs(vals["APPLES"]-1) > 0.001) {
        cout << "YA" << "\n";
    } else {
        cout << "NAW" << "\n";
    }
}
