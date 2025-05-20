#include <bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define int long long
const int N = 5e5 + 3;
int qs[N], ar[N], res[N];

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n; 

    map<int, vector<int>, greater<int>> ord;
    for(int i=1; i<=n; ++i) cin >> ar[i], qs[i] = qs[i-1] + ar[i], ord[ar[i]].pb(i);

    set<int> pos;
    for(auto [val, vec] : ord) {
        for(auto i : vec) {
            if((i>1 and ar[i]>ar[i-1]) or (i<n and ar[i]>ar[i+1])) {
                int l=0,r=n+1;
                auto t = pos.upper_bound(i);
                if(t!=pos.end()) r=*t;
                if(t!=pos.begin()) l=*(--t);
                int nw=qs[r-1]-qs[l];
                res[i]=nw;
                if(nw>ar[r]) res[i]=max(res[i],res[r]);
                if(nw>ar[l]) res[i]=max(res[i],res[l]);
            }else res[i]=val;
        }
        for(auto i : vec) pos.insert(i);
    }

    for(int i=1;i<=n;++i)cout << res[i] << ' ';
    return 0;
}