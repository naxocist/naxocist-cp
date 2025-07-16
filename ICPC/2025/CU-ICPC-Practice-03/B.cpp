#include <bits/stdc++.h>
using namespace std;

int main() {
  int k; cin >> k;
  string s; cin >> s;
  vector<int> cnt(26);
  for(char c : s) {
    cnt[c-'a'] ++;
  }

  string res;
  for(int i=0; i<26; ++i) {
    int x = cnt[i];
    if(!x) continue ;
    if(x%k) cout << -1, exit(0);

    int t = x/k;
    while(t--) res += 'a' + i;
  }

  while(k--) cout << res;
  return 0;
}
