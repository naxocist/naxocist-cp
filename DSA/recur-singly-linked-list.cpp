#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define all(x) begin(x), end(x)
#define pb emplace_back
#define dump(a) while(a.size())a.pop();
#define p(x) cout << #x << " = " << x << '\n';
#define p2(x) cout << #x << " = {" << x.f << ',' << x.s << "}\n";
#define pv(a) cout << #a << " = "; for(auto _x : a) cout << _x << ' '; cout << '\n';
#define pv2(a) cout << #a << " = "; for(auto [_x,_y] : a)cout << '{' << _x << ',' << _y << "} "; cout << '\n';
#define pa(a,n) cout << #a << " = "; for(int _i = 1; _i <= n; ++_i)cout << a[_i] << ' '; cout << '\n';
#define pa0(a,n) cout << #a << " = "; for(int _i = 0; _i < n; ++_i)cout << a[_i] << ' '; cout << '\n';

#define INF 2e9
#define LINF 2e18
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a,b)(rng); }
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a,b)(rng); }

struct node {
  node *r;
  int v;
  node(int x): v(x), r(nullptr) {}
};

using pnode = node*;

void print(pnode t) {
  if(!t) return ;
  cout << t->v << ' ';
  print(t->r);
}

void append(pnode &t, int x) {
  if(!t) return void(t = new node(x));
  append(t->r, x);
}

void prepend(pnode &t, int x) {
  pnode nw = new node(x);
  nw->r = t;
  t = nw;
}

void del_node(pnode &t) {
  pnode tmp = t;
  swap(t, t->r);
  delete tmp; // frees memory allocated by the target node
}

void pop_front(pnode &t) {
  if(!t) return ;
  del_node(t);
}

void pop_back(pnode &t) {
  if(!t) return ;
  if(!t->r) return del_node(t);
  pop_back(t->r);
}

void insert(pnode &t, int x, int y) {
  // assume valid insertion index
  if(!y) return void(prepend(t, x));
  insert(t->r, x, y-1);
}

void rem_val(pnode &t, int x) {
  if(!t) return ;
  if(t->v == x) return del_node(t);
  rem_val(t->r, x);
}

void rem_idx(pnode &t, int x) {
  if(x == 0) return del_node(t);
  rem_idx(t->r, x - 1);
}

int find_val(pnode &t, int x, int idx = 0) {
  if(!t) return -1;
  if(t->v == x) return idx;
  return find_val(t->r, x, idx + 1);
}

int get_idx(pnode &t, int x) {
  // assume valid idx
  if(x == 0) return t->v;
  return get_idx(t->r, x - 1);
}

pnode reverse(pnode &t) {
  if(!t or !t->r) return t;
  pnode nw = reverse(t->r);
  t->r->r = t;
  t->r = nullptr;
  return nw;
}

void reverse_iter(pnode &t) {
  pnode prv = nullptr;
  pnode crr = t;
  pnode nxt = t->r;
  while(crr->r) {
    nxt = crr->r;
    crr->r = prv;
    prv = crr;
    crr = nxt;
  }

  t = prv;
}

void solve() {
  /*
  # assume valid input
  -1 - exit
  p - print 

  ap - append x
  pp - prepend x
  is - insert x y

  pf - pop front
  pb - pop back
  rv - remove val x (first occurence only)
  ri - remove idx x

  fv - find val x
  gi - get idx x

  rev - reverse
  */

  pnode t = nullptr;
  while(1) {
    string o; int x, y; cin >> o;
    if(o == "-1") break ;
    if(o != "p" and o != "rev" and o != "pf" and o != "pb") cin >> x;
    if(o == "is") cin >> y;

    if(o == "p") {
      cout << "print: ";
      print(t); cout << ln; 
    }
    else if(o == "ap") {
      append(t,x); 
      cout << "appended " << x << ln; 
    }
    else if(o == "pp") { 
      prepend(t,x); 
      cout << "prepended " << x << ln; 
    }
    else if(o == "is"){
      insert(t,x,y); 
      cout << "inserted " << x << " at index " << y << ln; 
    }
    else if(o == "pf"){
      pop_front(t);
      cout << "popped front\n";
    }
    else if(o == "pb"){
      pop_back(t);
      cout << "popped back\n";
    }
    else if(o == "rv"){
      rem_val(t,x); 
      cout << "removed " << x << ln; 
    }
    else if(o == "ri"){
      rem_idx(t,x); 
      cout << "removed idx " << x << ln; 
    }
    else if(o == "fv"){
      cout << "found " << x << " at idx " << find_val(t,x) << ln; 
    }
    else if(o == "gi"){
      cout << "idx " << x << " is " << get_idx(t,x) << ln; 
    }
    else if(o == "rev"){
      // t = reverse(t);
      reverse_iter(t);
      cout << "reversed\n";
    }
    else {
      cout << "Invalid command" << ln;
    }
  }

  cout << "ENDED" << ln;
  return ;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int TC = 1;
  // cin >> TC; 
  while(TC--) solve();
  return 0;
}
