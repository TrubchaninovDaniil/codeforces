#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

vector<vector<ll>> g;
vector<ll> leaf;
bool ok;

pair<ll, ll> dfs(int u, int p) {
    if (!ok) return {0, 0};

    if (leaf[u] != 0) {
        for (int v : g[u]) {
            if (v != p) {
                ok = false;
                return {0, 0};
            }
        }
        return {leaf[u], leaf[u]};
    }

    vector<pair<ll, ll>> segs;
    for (ll v : g[u]) {
        if (v != p) {
            segs.push_back(dfs(v, u));
            if (!ok)
                return {0, 0};
        }
    }

    if (segs.empty()) {
        ok = false;
        return {0, 0};
    } 

    vector<pair<ll, ll>> sorted_segs = segs;
    sort(sorted_segs.begin(), sorted_segs.end());

    for (size_t i = 0; i < sorted_segs.size() - 1; ++i) {
        if (sorted_segs[i].second + 1 != sorted_segs[i + 1].first) {
            ok = false;
            return {0, 0};
        }
    }

    ll start_pos = -1;
    for (size_t i = 0; i < segs.size(); i++) {
        if (segs[i] == sorted_segs[0]) {
            start_pos = i;
            break;
        }
    }

    if (start_pos == -1) {
        ok = false;
        return {0, 0};
    }

    for (size_t i = 0; i < segs.size(); i++) {
        if (segs[(start_pos + i) % segs.size()] != sorted_segs[i]) {
            ok = false;
            return {0, 0};
        }
    }

    return {sorted_segs[0].first, sorted_segs.back().second};

}

void solve() {
    ll n;
    cin >> n;

    g.assign(n + 1, vector<ll>());
    leaf.assign(n + 1, 0);
    ok = true;

    for (size_t i = 2; i <= n; i++) {
        ll p;
        cin >> p;
        g[p].push_back(i);
        g[i].push_back(p);
    }

    ll k = 0;
    for (size_t i = 1; i <= n; i++) {
        cin >> leaf[i];
        k = max(k, leaf[i]);  
    }

    pair<ll, ll> res = dfs(1, -1);
    
    if (ok && res.first == 1 && res.second == k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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