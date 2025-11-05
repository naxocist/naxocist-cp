#include <bits/stdc++.h>
using namespace std;


template<typename T>
class Box {
  public:
    T value;
    Box(T v) {
      value = v;
    }

    void show() {
      cout << "Value: " << value << '\n';
    }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Box<int> intBox(12345);
  Box<string> stringBox("Hello World");
  Box TBox(3.2);

  TBox.show();
  intBox.show();
  stringBox.show();
}

