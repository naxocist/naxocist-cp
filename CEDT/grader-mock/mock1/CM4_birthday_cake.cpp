#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  int ar[n];
  for(int i=0; i<n; ++i) cin >> ar[i];

  int mx = 0, l = 0, r = 0;
  for(int i=0; i<n; ++i) {
    int s = 0;
    for(int j=i; j<n && j-i+1 <= k; ++j) {
      if(ar[j] > ar[i]) break ;

      s += ar[j];

      if(s > mx) {
        mx = s, l = i, r = j;
      }else if(mx == s) {
        if(r-l < j-i) l = i, r = j;
        else if(r-l == j-i) {
          for(int k=0; k<j-i+1; ++k) {
            if(ar[i+k] > ar[l+k]) {
              l = i, r = j;
              break; 
            }else if(ar[i+k] < ar[l+k]){
              break ;
            }
          }
        }
      }
    }
  }

  cout << mx << '\n';
  for(int i=l; i<=r; ++i) cout << ar[i] << ' ';
  return 0;
}
