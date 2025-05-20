#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "-------\n";
#define all(x) begin(x), end(x)
#define cntBit(x) __builtin_popcount(x)
#define pb emplace_back
using ll = long long;

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s, t; cin >> s;
	for(auto c : s) {
		for(int i=0; i<t.size(); ++i) {
			if(c <= t[i]) {
				t[i] = c; goto g;
			}
		}
		t += c;
		g:;
	}
	cout << t.size();
	return 0;
}