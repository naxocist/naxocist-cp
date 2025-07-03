#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll mod = 1573153713573157173;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int q; cin >> q; 

	int n = 500000;
	vector<ll> f(n); f[0] = 1;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=5; ++j) if(i-j>=0) f[i] += f[i-j], f[i] %= mod;
	}

	while(q--) {
		int x; cin >> x; cout << f[x] << '\n';
	}
	return 0;
}
