#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    char g[5][5] = {
        {'G', 'G', 'G', 'G', 'G'},
        {'G', '.', '.', '.', '.'},
        {'G', '.', '.', 'G', 'G'},
        {'G', '.', '.', '.', 'G'},
        {'G', 'G', 'G', 'G', 'G'}
    };
    for (int i=0; i<5; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<5; k++) {
                for (int l=0; l<N; l++) {
                    cout << g[i][k];
                }
            }
            cout << '\n';
        }
    }
}
