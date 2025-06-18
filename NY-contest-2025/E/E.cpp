#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n; cin >> n;
	for(int i=1; i<n; ++i) {
		cout << i << ' ' << i+1 << '\n';
	}
	return 0;
}
