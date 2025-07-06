#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  int n = s.size();

  if(isdigit(s[0])) {
    for(int i=0; i+1<n; i+=2) {
      int k = s[i]-'0';
      while(k--) cout << s[i+1];
    }
  }else {
    int cnt = -1;
    char pv = '.';
    for(char c : s) {
      if(c != pv) {
        if(cnt != -1) cout << cnt << pv;
        cnt = 1;
      }else cnt ++;

      pv = c;
    }
    cout << cnt << pv;
  }
  return 0;
}