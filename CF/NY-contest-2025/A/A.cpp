#include <bits/stdc++.h>
using namespace std;

#define ln '\n'

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	map<char, int> mp;

	int k; cin >> k;
	while(k --) {
		string s; cin >> s;
		if(s == "get") {
			string t; cin >> t;
			if(t.size() == 1) {
				if(mp.find(t[0]) == mp.end()) cout << "?\n";
				else cout << mp[t[0]] << ln;
				continue ;
			}

			char op = t[1];
			char a = t[0], b = t[2];
			if(mp.find(a) == mp.end() or mp.find(b) == mp.end()) {
				cout << '?' << '\n'; continue ;
			}

			int x = mp[a], y = mp[b];
			if(op == '+') {
				cout << x + y << ln;
			}else if(op == '-') {
				cout << x - y << ln;
			} else if(op == '*') {
				cout << x * y << ln;
			}else if(op == '=') {
				cout << (x == y ? "YES" : "NO") << ln;
			}else if(op == '<') {
				cout << (x < y ? "YES" : "NO") << ln;
			}else if(op == '>') {
				cout << (x > y ? "YES" : "NO") << ln;
			}else {
				cout << x << y << ln;
			}

		}else {
			int x; char t; cin >> t >> x;
			mp[t] = x;
		}
	}
	return 0;
}
