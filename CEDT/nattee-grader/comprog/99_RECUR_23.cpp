#include <iostream>
#include <map>
using namespace std;
int F(int n) { // Fibonacci number
  if(n <= 1) return n;

  int m = (n + 1)/2;
  if(n&1^1) return (2*F(m - 1) + F(m))*F(m);
  return F(m)*F(m) + F(m-1)*F(m-1);

}
int M(int n) { // Motzkin number
  if(n <= 1) return 1;
  int res = M(n-1);

  for(int k=0; k<=n-2; ++k) {
    res += M(k)*M(n-2-k);
  }

  return res;
}
int S(int n) { // Schröder–Hipparchus Number
  if(n <= 2) return 1;
  return ((6*n - 9)*S(n-1) - (n-3)*S(n-2)) / n;
}

int D(int n) { // Derangement
  if(n == 0) return 1;
  return n*D(n-1) + (n&1 ? -1 : 1);
}
int main() {
  map<string, int(*)(int)> func = {{"F",F}, {"M",M}, {"S",S}, {"D",D}};
  string fn;
  int p;
  while (cin >> fn >> p) {
    if (func.find(fn) != func.end())
      cout << fn << '(' << p << ") = " << func[fn](p) << endl;
  }
  return 0;
}
