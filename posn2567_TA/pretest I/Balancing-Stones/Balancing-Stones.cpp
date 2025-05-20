// Tanawin Thongbai
// C2T13 - Balancing-Stones
#include <bits/stdc++.h>
using namespace std;

constexpr unsigned N = 100000 + 5;
auto dsu = array<int, N>();
auto dsu_sz = array<int, N>();
auto dsu_ratio = array<double, N>();

int dsu_find(int u) {
    if(dsu[u] == u) {
        return u;
    }
    int v = dsu[u];
    dsu[u] = dsu_find(v);
    dsu_ratio[u] *= dsu_ratio[v];
    return dsu[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(4) << scientific;

    int n, Q;
    cin >> n >> Q;
    for(int i = 1; i <= n; ++i) {
        dsu[i] = i;
        dsu_sz[i] = 1;
        dsu_ratio[i] = 1.0;
    }
    while(Q--) {
        char cmd;
        cin >> cmd;
        if(cmd == 'A') { // Add Result
            int u, x, v, y;
            cin >> u >> x >> v >> y;
            int hu = dsu_find(u), hv = dsu_find(v);
            if(hu == hv) { // Known Ratio -> Already Known
                cout << "Already Known\n";
            } else { // New Data -> Union
                double hu_over_u = dsu_ratio[u]; // hu / u
                double hv_over_v = dsu_ratio[v]; // hv / v
                if(dsu_sz[hu] >= dsu_sz[hv]) { // Connect hv to hu
                    dsu[hv] = hu;
                    dsu_ratio[hv] = hu_over_u / hv_over_v * y / x; // (hu / u) * (v / hv) * (u / v) = hu / hv
                    dsu_sz[hu] += dsu_sz[hv];
                } else { // Connect hu to hv
                    dsu[hu] = hv;
                    dsu_ratio[hu] = hv_over_v / hu_over_u * x / y; // (hv / v) * (u / hu) * (v / u) = hv / hu
                    dsu_sz[hv] += dsu_sz[hu];
                }
            }
        } else if(cmd == 'T') { // Test
            int a, b, c;
            cin >> a >> b >> c;
            if(a == b) {
                cout << 0.0 << '\n';
                continue;
            }
            int ha = dsu_find(a), hb = dsu_find(b), hc = dsu_find(c);
            if(ha != hb || hb != hc) { // Not Connected -> Insufficient Data
                cout << "Insufficient Data\n";
                continue;
            }
            double a_over_c = dsu_ratio[c] / dsu_ratio[a]; // (h / c) * (a / h) = a / c
            double b_over_c = dsu_ratio[c] / dsu_ratio[b]; // (h / c) * (b / h) = b / c
            double ans = abs(a_over_c - b_over_c);
            cout << ans << '\n';
        }
    }
    

    return 0;
}
