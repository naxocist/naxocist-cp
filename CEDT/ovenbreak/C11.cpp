#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  string s; cin >> s;
  int n = s.size();

  string a = "###", b = "####";
  for(int i=0; i<n; ++i) {
    char c = i%2 ? '*' : '^';
    a += c, a += "#", a += c;
  }
  a += "###";

  for(int i=0; i<n; ++i) {
    char c = i%2 ? '^' : '*';
    if(i) b += "##";
    b += c;
  }
  b += "####";

  string ra = a, rb = b;
  reverse(all(ra)), reverse(all(rb));
  cout << "  " << a << "||" << ra << ln;
  cout << " " << b << " " << "||" << " " << rb << ln;

  string l = "###";
  int k = 3*n; while(k--) l += "-";
  l += "###";
  cout << l << "  " << "||" << "  " << l << ln;

  string r = "###";
  k = n; while(k--) r += " ";
  r += s;
  k = n; while(k--) r += " ";
  r += "###";
  cout << r << "  " << "||" << "  " << r << ln;

  cout << l << "  " << "||" << "  " << l << ln;

  cout << " " << b << " " << "||" << " " << rb << ln;
  cout << "  " << a << "||" << ra << ln;
  return 0;
}