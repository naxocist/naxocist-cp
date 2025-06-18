#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n; cin >> n;
	int p = -1, cnt = 0, res = 1;
	for(int i=0; i<n; ++i) {
		int x; cin >> x;
		if(x >= p) cnt ++;
		else cnt = 1;
		res = max(res, cnt);
		p = x;
	}

	if(res == 1) cout << -1 << ln;
	else cout << res << ln;
	return 0;
}
