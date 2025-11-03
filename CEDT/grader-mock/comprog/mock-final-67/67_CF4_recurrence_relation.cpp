#include <iostream>
using namespace std;
int S(int n, int k) {
  if(n == 0 and k == 0) return 1;
  if(n == 0 or k == 0) return 0;

  return k*S(n-1, k) + S(n-1, k-1);
}

int B(int n) {
  // Bell number
  if(n == 0) return 1;

  int nfac = 1;
  for(int i=1; i<n; ++i) nfac *= i;

  int s = 0;
  for(int k=0; k<n; ++k) {
    int nchoosek = nfac;
    for(int i=1; i<=k; ++i) nchoosek /= i;
    for(int i=1; i<n-k; ++i) nchoosek /= i;
    s += nchoosek*B(k);
  }
  
  return s;
}
int T(int n, int x) {
  // Chebyshev polynomials
  if(n == 1) return x;
  if(n == 0) return 1;

  return 2*x*T(n-1,x) - T(n-2, x);
}
int main() {
  string fn;
  int i, j;
  while (cin >> fn) {
    if (fn == "S") {
      cin >> i >> j;
      printf("S(%d, %d) = %d\n", i, j, S(i,j));
    } else if (fn == "B") {
      cin >> i;
      printf("B(%d) = %d\n", i, B(i));
    } else if (fn == "T") {
      cin >> i >> j;
      printf("T(%d, %d) = %d\n", i, j, T(i,j));
    }
  }
  return 0;
}

