#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
#define ll long long
#define pii pair<int, int>
#define all(x) begin(x), end(x)
#define pb emplace_back

using pi = pair<int, int>;

const int LG = 20;
const int N = 1e5 + 3;

struct node {
  int val;
  node *nxt = nullptr;
};

node *head = nullptr;

node *createNode(int val) {
  node *newNode = new node;
  newNode->val = val;
  return newNode;
}


int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n; cin >> n;

  head = createNode(n);
  cout << head->val;
}

