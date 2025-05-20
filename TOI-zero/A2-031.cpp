#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;
  string a, b; char c;
  for(int i=0; i<n; ++i) cin >> c, a += c;
  for(int i=0; i<n; ++i) cin >> c, b += c;

  int q; cin >> q;
	while(q--) {
		int x, y; cin >> x >> y >> c;
		if(x == 1) a[y] = c;
		else b[y] = c;
	}

	unordered_map<char, char> um = {
		{'A', 'T'},
		{'T', 'A'},
		{'G', 'C'},
		{'C', 'G'}
	};

	int res = 0;
	for(int i=0; i<n; ++i) res += (um[a[i]] != b[i]);

	for(auto c : a) cout << c << ' '; cout << ln;
	for(auto c : b) cout << c << ' '; cout << ln;
	cout << res;
  return 0;
}
