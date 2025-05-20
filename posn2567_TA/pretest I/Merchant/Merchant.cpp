#include <bits/stdc++.h>
using namespace std;

void solve() {
	int m, n; cin >> m >> n;

	int mx_sell = -INT_MAX, mx_sell_buy = -INT_MAX;
	for(int i=0; i<m; ++i) {
		int sell, buy; cin >> sell >> buy;
		mx_sell = max(mx_sell, sell);
		mx_sell_buy = max(mx_sell_buy, sell-buy);
	}

	if(mx_sell >= n) {
		cout << 1 << '\n'; return ;
	}

	if(mx_sell_buy <= 0) {
		cout << -1 << '\n'; return ;
	}

	// (a + b - 1) / b = ceil(a/b);
	cout << 1 + ((n-mx_sell + mx_sell_buy - 1)/mx_sell_buy) << '\n';
}

int main() {
	int q; cin >> q;
	while(q--) solve();
	return 0;
}