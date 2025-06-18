#include <bits/stdc++.h>
using namespace std;

#define ln '\n'

void solve() {
	int n, k; cin >> n >> k;
	bool res = true;

	map<int, multiset<int>> mp, mp2; 
	for(int i=0; i<n; ++i) {
		int x; cin >> x;
		mp[i%k].insert(x);
	}

	for(int i=0; i<n; ++i) {
		int x; cin >> x;
		mp2[i%k].insert(x);
	}

	if(mp == mp2) cout << "YES" << ln;
	else cout << "NO" << ln;
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}

