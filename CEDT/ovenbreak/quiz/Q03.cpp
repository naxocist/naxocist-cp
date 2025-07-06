#include <bits/stdc++.h>
using namespace std;

int f(string x) {
  if(isdigit(x[0])) return stoi(x);

  if(x == "J") return 11;
  if(x == "Q") return 12;
  if(x == "K") return 13;
  return 14;
}


using pi = pair<int, char>;
vector<pi> v;

bool fsamex(int l, int r) {
  int px = -1;
  for(int i=l; i<=r; ++i) {
    int x = v[i].first;
    if(px != -1 and x != px) return 0;
    px = x;
  }
  return 1;
}

bool four() {
  return fsamex(0,3) or fsamex(1,4);
}

bool three() {
  return fsamex(0,2) or fsamex(1,3) or fsamex(2,4);
}


bool full() {
  if(fsamex(0,2) and fsamex(3,4) and v[0].first != v[4].first)
    return 1;

  if(fsamex(0,1) and fsamex(2,4) and v[0].first != v[4].first)
    return 1;

  return 0;
}

bool onepair() {
  for(int i=0; i<4; ++i) {
    if(v[i].first == v[i+1].first) return 1;
  }
  return 0;
}

bool twopair() {
  for(int i=0; i<4; ++i) {
    if(v[i].first == v[i+1].first) {
      for(int j=i+2; j+1<5; ++j) {
        if(v[j].first == v[j+1].first and v[i].first != v[j].first) return 1;
      }
    }
  }
  return 0;
}
int main() {
  int k = 5;

  bool samey = 1;
  char py = '.';
  int px = -1;
  int sx = 0;
  bool seq = 1;

  for(int i=0; i<k; ++i) {
    string x; char y; cin >> x >> y;
    int xx = f(x);
    sx += xx;
    v.emplace_back(xx,y);

    if(px != -1 and xx != px-1) seq = 0; 

    if(py != '.' and py != y) samey = 0;
    py = y;
    px = xx;
  }

  if(samey and sx == 60) {
    cout << "royal flush";
  }else if(samey and seq) {
    cout << "straight flush";
  }else if(four()) {
    cout << "four of a kind";
  }else if(full()) {
    cout << "full house";
  }else if(samey) {
    cout << "flush";
  }else if(seq) {
    cout << "straight";
  }else if(three()) {
    cout << "three of a kind";
  }else if(twopair()) {
    cout << "two pair";
  }else if(onepair()) {
    cout << "pair";
  }else {
    cout << "high card";
  }

  return 0;
}