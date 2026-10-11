#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;

    vector<ll> p(n + 1);

    for (size_t i = 2; i <= n; i++)
        cin >> p[i];

    ll m;
    cin >> m;
    
    vector<bool> dam(n + 1, false);
    for (size_t i = 0; i < m; i++) {
        int a;
        cin >> a;
        dam[a] = true;
    }

    vector<bool> has_dam = dam;
    for (size_t i = n; i >= 2; i--) {
        if (has_dam[i]) {
            has_dam[p[i]] = true;
        }
    }

    vector<vector<ll>> dam_children(n + 1);
    for (size_t i = 1; i <= n; i++) {
        if (has_dam[i]) {
            dam_children[p[i]].push_back(i);
        }
    }

    vector<ll> cameras;
    for (size_t u = 1; u <= n; u++) {
        ll C = dam_children[u].size();
        ll D = dam[u] ? 1 : 0;
        ll T = C + D;

        if (T > 1) {
            for (size_t i = 0; i < T - 1; i++) {
                cameras.push_back(dam_children[u][i]);
            }
        }
    }

    cout << m - 1;
    for (auto & v : cameras) 
        cout << " " << v;
    
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