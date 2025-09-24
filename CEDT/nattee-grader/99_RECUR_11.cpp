#include <bits/stdc++.h>
using namespace std;

map<int, string> mp;

string dec2hex(int d) {
  if(d < 16) return mp[d];
  return dec2hex(d/16) + dec2hex(d%16);
}

int main() {

  for(int i=0; i<16; ++i) {
    if(i < 10) mp[i] = i + '0';
    else mp[i] = 'A' + i - 10;
  }

  int d;
  while (cin >> d) {
    cout << d << " -> " << dec2hex(d) << endl;
  }
  return 0;
} 
