#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string a, b, c, d;
  map<string, int> mp;
  while(cin >> a >> b >> c >> d) {
    int i = d.find(':');
    int m = stoi(d.substr(0, i)), s = stoi(d.substr(i + 1));
    s += 60*m;
    mp[c] += s;
  }

  vector<pair<int, string>> v;
  for(auto [a, b] : mp) v.pb(b, a);
  sort(v.rbegin(), v.rend());
  for(int i=0; i<min(3, (int)v.size()); ++i) {
    auto [a, b] = v[i];
    int m = a/60, s = a%60;
    cout << b << " --> " << m << ":" << s << ln;
  }
  return 0;
}

