#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s; cin >> s; for(auto &c : s) c = toupper(c);
  char x = s.back(); s.pop_back();

  if(s == "A") cout << "ace";
  else if(s == "J") cout << "jack";
  else if(s == "K") cout << "king";
  else if(s == "Q") cout << "queen";
  else cout << s;

  cout << " of ";

  if(x == 'H') cout << "hearts";
  if(x == 'D') cout << "diamonds";
  if(x == 'S') cout << "spades";
  if(x == 'C') cout << "clubs";
  return 0;
}
