#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 3;
ll present[N]; // present[i] : the number of present types that are >= i  

int main() {
	int n, m; cin >> n >> m;

	int mx_A = 0;
	for(int i=0; i<n; ++i) {
		int x; cin >> x;
		mx_A = max(mx_A, x), present[x] ++;
	}

	for(int i=mx_A; i>=0; --i) present[i] += present[i + 1];

	for(int i=1; i<=m; ++i) {
		ll res = 0;
		for(int j=i; j<=mx_A; j+=i) res += present[j];
		cout << res << '\n';
	}
	return 0;
}