#include <bits/stdc++.h>
using namespace std;
const int MM = 105;
double arr[MM];
map<int, int> freq;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int s = 0;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
        s += arr[i];
        freq[arr[i]]++;
    }
    // Find mean median mode
    double mean = 1.0*s / N, median, mode;
    sort(arr, arr+N);
    if (N%2 == 1) {
        median = 1.0*arr[N/2];
    } else {
        median = 1.0*(arr[N/2-1] + arr[N/2]) / 2;
    }
    vector<int> modenums;
    int maxnum = 0;
    for (auto i : freq) {
        if (i.second > maxnum) {
            maxnum = i.second;
            modenums.clear();
            modenums.push_back(i.first);
        } else if (i.second == maxnum) {
            modenums.push_back(i.first);
        }
    }

    cout << mean << "\n" << median << "\n";
    for (auto i : modenums) {
        cout << i << " ";
    }
    cout << "\n";
}