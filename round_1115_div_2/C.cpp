#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n, 0);
    for (ll& l : a) cin >> l;

    vector<vector<ll>> tower(n, vector<ll>(m, 0));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> tower[i][j];
        }
    }

    ll ans = m;
    vector<ll> best_blocks;

    for (ll i = n - 1; i >= 0; i--) {
        sort(tower[i].rbegin(), tower[i].rend());

        vector<ll> new_best;
        ll p1 = 0, p2 = 0;

        while (new_best.size() < m) {
            if (p1 < best_blocks.size() && p2 < tower[i].size()) {
                if (best_blocks[p1] > tower[i][p2]) {
                    new_best.push_back(best_blocks[p1++]);
                } else {
                    new_best.push_back(tower[i][p2++]);
                }
            } else if (p1 < best_blocks.size()) {
                new_best.push_back(best_blocks[p1++]);
            } else {
                new_best.push_back(tower[i][p2++]);
            }
        }
        
        best_blocks = new_best;

        ll pref_sum = 0;
        for (ll j = 0; j < best_blocks.size(); j++) {
            pref_sum += best_blocks[j];
        
            if (pref_sum >= a[i]) {
                ans = min(ans, j + 1);
                break;
            }
        }

    }

    cout << ans << "\n";

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