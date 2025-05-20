#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int d, m; cin >> d >> m;
  if(m == 1) {
  	if(d <= 19) cout << "capricorn";
  	else cout << "aquarius";
  } 

  if(m == 2) {
  	if(d <= 18) cout << "aquarius";
  	else cout << "pisces";
  } 

  if(m == 3) {
  	if(d <= 20) cout << "pisces";
  	else cout << "aries";
  }

  if(m == 4) {
  	if(d <= 19) cout << "aries";
  	else cout << "taurus";
  }

  if(m == 5) {
  	if(d <= 20) cout << "taurus";
  	else cout << "gemini";
  }

  if(m == 6) {
  	if(d <= 21) cout << "gemini";
  	else cout << "cancer";
  }

  if(m == 7) {
  	if(d <= 22) cout << "cancer";
  	else cout << "leo";
  }
  
  if(m == 8) {
  	if(d <= 22) cout << "leo";
  	else cout << "virgo";
  }
  
  if(m == 9) {
  	if(d <= 22) cout << "virgo";
  	else cout << "libra";
  }
  
  if(m == 10) {
  	if(d <= 23) cout << "libra";
  	else cout << "scorpio";
  }
  
  if(m == 11) {
  	if(d <= 21) cout << "scorpio";
  	else cout << "sagittarius";
  }
  
  if(m == 12) {
  	if(d <= 21) cout << "sagittarius";
  	else cout << "capricorn";
  }
  
  return 0;
}
