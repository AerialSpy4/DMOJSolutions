#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int MOD = 1e9+7;
void op(int F[2][2], int M[2][2]) {
	int a = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int b = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int c = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int d = F[1][0] * M[0][1] + F[1][1] * M[1][1];
	F[0][0] = a % MOD;
	F[0][1] = b % MOD;
	F[1][0] = c % MOD;
	F[1][1] = d % MOD;
}
void ex(int F[2][2], int x) {
	if (x <= 1) return;
	int arr[2][2] = {{1, 1},{1, 0}};
	ex(F, x/2); op(F, F);
	if (x & 1) op(F, arr);
}
int fibo(int x) {
	int F[2][2] = {{1, 1},{1, 0}};
	if (x == 0) return 0;
	else ex(F, x-1);
	return F[0][0];
}
int32_t main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << fibo(n);
}