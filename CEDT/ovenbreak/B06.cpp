#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s, m, i; cin >> s >> m >> i;

  string yes = "Ingredient accepted!";
  string no = "Ingredient rejected!";
  if(s == "spring" or s == "summer") {
    if(m == "full") {
      if(i == "honey" or i == "milk") cout << yes;
      else cout << no;
      return 0;
    }

    if(m == "new" and i != "chocolate") cout << no;
    else cout << yes;
    return 0;
  }

  if(s == "autumn" or s == "winter") {
    if(m == "waning" or m == "new") {
      if(i == "chocolate" or i == "milk") cout << yes;
      else cout << no;
      return 0;
    }
    cout << yes;
    return 0;
  }

  cout << no;
  return 0;
}