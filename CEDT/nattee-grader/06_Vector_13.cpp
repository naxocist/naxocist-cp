#include <iostream>
#include <vector>
using namespace std;
vector<string> split(string line, char delimiter) {

  vector<string> res;
  line += delimiter;
  int n = line.size(), p = 0; 
  for(int i=0; i<n; ++i) {
    if(line[i] == delimiter) {
      if(i-p) res.emplace_back(line.substr(p, i-p));
      p = i + 1;
    }
  }

  return res;
}

int main() {
 string line;
 getline(cin, line);
 string delim;
 getline(cin, delim);
 for (string e : split(line, delim[0])) {
 cout << '(' << e << ')';
 }
}
