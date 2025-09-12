#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string a;
  getline(cin, a);
  multiset<char> s, z;
  for(char c : a) if(isalpha(c)) s.insert(tolower(c));
  getline(cin, a);
  for(char c : a) if(isalpha(c)) z.insert(tolower(c));

  if(s == z) cout << "YES";
  else cout << "NO";
  return 0;
}

