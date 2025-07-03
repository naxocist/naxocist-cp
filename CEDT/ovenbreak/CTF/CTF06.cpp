#include <iostream>
using namespace std;
int main() {
  string a;
  cin >> a;
  string x = "";
  for (int i = 0; i < a.length(); i++) {
    char c = a[i];
    if (c >= 'a' && c <= 'z') {
      c = ((c - 'a' - 17 + 52) % 26) + 'a';
    } else if (c >= 'A' && c <= 'Z') {
      c = ((c - 'A' - 21 + 52) % 26) + 'A';
    } else if (c >= '0' && c <= '9') {
      c = ((c - '0' - 8 + 10) % 10) + '0';
    } else {
      c = c;
    }
    x += c;
  }
  cout << "Encoded message: " << x << endl;
  return 0;
}
// XZYO.Jmvesivrb.2tvuk81Z9Z9aPsElW