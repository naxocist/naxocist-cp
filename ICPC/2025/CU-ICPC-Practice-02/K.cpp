#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define all(x) begin(x), end(x)
#define pb emplace_back

const int N = 5e3 + 1;

int get(int a, int b) {
  cout << "? " << a << ' ' << b << endl;
  int x; cin >> x;
  return x;
}

/*
5
1 2 3 4 5
*/
int32_t main() {
  int n; cin >> n;
  int ar[n + 1];
  int a = get(1, 2), b = get(2, 3), c = get(1, 3);
  ar[1] = (a+b+c)/2-b;
  ar[2] = a - ar[1];
  ar[3] = b - ar[2];

  for(int i=4; i<=n; ++i) {
    ar[i] = get(i,i-1)-ar[i-1];
  }

  cout << "! ";
  for(int i=1; i<=n; ++i) cout << ar[i] << ' ';
  cout << endl;
  return 0;
}