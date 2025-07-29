#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  s = "." + s;

  vector<int> dp(n + 1);
  stack<int> st;

  int mx = 0, cnt = 1;
  for(int i=1; i<=n; ++i) {
    char c = s[i];
    if(c == ')') {
      if(st.empty()) continue ;
      int j = st.top(); st.pop();
      dp[i] = i - j + 1 + dp[j-1];
      if(dp[i] > mx) mx = dp[i], cnt = 1;
      else if(dp[i] == mx) cnt ++;
    }
    else {
      st.emplace(i);
    }
  }
  cout << mx << ' ' << cnt;
  return 0;
}
