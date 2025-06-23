#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back

#define all(x) x.begin(), x.end()

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  set<char> no;
  map<char, int> mp;
  for(int i=0; i<7; ++i) mp['A' + i] = 0;
  while(1) {
    string s; cin >> s;
    if(s == "!") break ;

    for(char c : s) if(no.find(c) == no.end()) mp[c] ++;

    int mn = 1e9, cnt = 0;
    for(auto [a, b] : mp) mn = min(mn, b);
    for(auto [a, b] : mp) if(b == mn) cnt ++;

    if(cnt > 1 or mp.size() == 1) continue ;

    for(auto it=mp.begin(); it!=mp.end();) {
      if(it->second == mn) no.insert(it->first), it = mp.erase(it);
      else it ++;
    }
  }

  multimap<int, char> rmp;
  for(auto [a, b] : mp) rmp.insert({-b, a});

  cout << rmp.size() << '\n';
  for(auto [a, b] : rmp) cout << b << ' ' << -a << '\n';
  return 0;
}
