#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int n; cin >> n;

  string ar[10] = {"Robert", "William", "James", "John", "Margaret", "Edward", "Sarah", "Andrew", "Anthony", "Deborah"};
  string ar2[10] = {"Dick", "Bill", "Jim", "Jack", "Peggy", "Ed", "Sally", "Andy", "Tony", "Debbie"};
  while(n--) {
    string s; cin >> s;

    bool found = 0;
    for(int i=0; i<10; ++i) {
      if(s == ar[i]) {
        cout << ar2[i] << ln; found = 1;
        break ;
      }else if(s == ar2[i]) {
        cout << ar[i] << ln; found = 1;
        break ;
      }
    }

    if(!found) cout << "Not found\n";
  }
  return 0;
}

