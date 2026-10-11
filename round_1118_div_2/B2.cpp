#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> count(m + 1, 0);
    vector<ll> pref(m + 1, 0);

    for (size_t i = 0; i < n; i++) {
        ll a;
        cin >> a;
        count[a]++;
    }

    for (size_t i = 1; i <= m; i++) 
        pref[i] = pref[i - 1] + count[i];
    

    ll maxk = min(m, 18LL);
    vector<ll> ans(maxk + 1, 0);

    vector<ll> p2(maxk + 1);
    for (size_t k = 1; k <= maxk; k++) 
        p2[k] = 1LL << k;
    
    for (ll i = 1; i <= m; i++) {
        
        vector<ll> current_k(maxk + 1, 0);

        for (ll j = 1; j * i <= m; j++) {
            ll le = j * i;
            ll rb = min(m, (j + 1) * i - 1);

            ll cnte = count[le];
            ll cntm = pref[rb] - pref[le];

            if (cnte == 0 && cntm == 0) 
                continue;

            for (size_t k = 1; k <= maxk; k++) {
                ll pq = p2[k];
                ll ve = (j <= pq) ? j : (pq - 1);
                ll vm = (j < pq) ? j : (pq - 1);
                current_k[k] += cnte * ve + cntm * vm;
            }
        }

        for (size_t k = 1; k <= maxk; k++) 
            ans[k] = max(ans[k], current_k[k]);
        
    }
   
    for (ll k = 1; k <= m; k++) {
        ll ak = min(k, maxk);
        cout << ans[ak] << (k == m ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

}