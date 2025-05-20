#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ln '\n'

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  cin.ignore();
  string a[3], b[3];
  for(int i=0; i<3; ++i) getline(cin, a[i]);
  for(int i=0; i<3; ++i) getline(cin, b[i]);

  map<string, int> mp = {
    {"     |  |", 1},
    {" _  _||_ ", 2},
    {" _  _| _|", 3},
    {"   |_|  |", 4},
    {" _ |_  _|", 5},
    {" _ |_ |_|", 6},
    {" _   |  |", 7},
    {" _ |_||_|", 8},
    {" _ |_| _|", 9},
    {" _ | ||_|", 0}
  };

  ll x = 0;
  for(int i=0; i<n; ++i) {
    string s; 
    x *= 10;
    for(int j=0; j<3; ++j) s += a[j].substr(3*i + i, 3);
    x += mp[s];
  }

  ll y = 0;
  for(int i=0; i<m; ++i) {
    string s; 
    y *= 10;
    for(int j=0; j<3; ++j) s += b[j].substr(3*i + i, 3);
    y += mp[s];
  }
  cout << x + y;
  return 0;
}

