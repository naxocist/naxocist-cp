#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int x, y;
int f(int h1, int h2, int b1, int b2) {
	int mx = 0;
	int f1 = min(h1, b1);
	if(f1) {
		int c = max(f(h1-f1, h2, b1-f1, b2), f(h2, h1-f1, b2, b1-f1));
		mx = min(x, f1) + c;
	}

	int d1 = min(h1, b2);
	if(d1) {
		int c = max(f(h1-d1, h2, b1, b2-d1), f(h2, h1-d1, b2-d1, b1));
		mx = max(mx, min(y, d1) + c);
	}

	return mx;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int h1, h2, b1, b2; cin >> h1 >> h2 >> b1 >> b2 >> x >> y;
  cout << f(h1, h2, b1, b2);
  return 0;
}
