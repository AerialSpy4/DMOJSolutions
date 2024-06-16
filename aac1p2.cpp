#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5+5;

#define int long long

#define endl "\n"

double speeds[1000005];

int32_t main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, d, k, x;
	cin >> n >> d >> k >> x;

	for (int i=0; i<n; i++) {
		cin >> speeds[i];
	}

	double p;
	cin >> p;

	for (int i=0; i<n; i++) {
		while (speeds[i] >= p) {
			if (k <= 0) {
				cout << "NO" << endl;
				return 0;
			}
			speeds[i] = floor(speeds[i] * (100-x)/100.0);
			k--;
		}
	}

	cout << "YES" << endl;
}