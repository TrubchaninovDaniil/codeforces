#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll M = 2000000;
vector<ll> spf(M, 0);
vector<ll> p_list;
vector<ll> p_idx(M, 0);

void pc() {
    for (size_t i = 2; i < M; i++) 
        spf[i] = i;
    
        for (ll i = 2; i * i < M; i++) {
            if (spf[i] == i) {
                for (ll j = i * i; j < M; j += i) 
                    if (spf[j] == j) 
                        spf[j] = i;
            
        }
    }

    for (ll i = 2; i < M; i++) {
        if (spf[i] == i) {
            ll pp = i;
            while (pp < M) {
                p_list.push_back(pp);
                pp *= i;
            }
        }
    }
    sort(p_list.begin(), p_list.end());
    for (ll i = 0; i < p_list.size(); i++) {
        p_idx[p_list[i]] = i;
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);

    for (size_t i = 1; i <= n; i++) 
        cin >> a[i];

    auto it = upper_bound(p_list.begin(), p_list.end(), n);
    ll K = (it - p_list.begin()) + 1; 

    ll N = 1;
    while (N < K) 
        N *= 2;

    vector<ll> ln(K, 0);
    vector<bool> valid(K, false);
    vector<ll> tree(2 * N, 0);
    vector<vector<pair<ll, ll>>> qu(n + 1);

    for (size_t i = 0; i < K; i++) {
        ln[i] = 0;
        valid[i] = false;
    }
    for (size_t i = 0; i < 2 * N; i++) 
        tree[i] = 0;

    for (size_t i = 1; i <= n; i++) 
        qu[i].clear();
    

    for (size_t i = 1; i <= n; i++) {
        ll temp = a[i];

        while (temp > 1) {
            ll p = spf[temp];
            ll pp = p;
            while (temp % p == 0) {
                temp /= p;
                ll k = p_idx[pp];
                if (k < K) {
                    ll R = i - 1;
                    ll A = ln[k];
                    if (R >= A + 1) qu[R].push_back({k, A});
                    ln[k] = i;
                }
                pp *= p;
            }
        }
    }

    for (ll k = 0; k < K; k++) {
        ll r = n;
        ll a = ln[k];
        if (r >= a + 1) 
            qu[r].push_back({k, a});
    }

    for (ll i = 1; i <= n; i++) {
        ll temp = a[i];

        while (temp > 1) {
            ll p = spf[temp];
            ll pp = p;
        
            while (temp % p == 0) {
                temp /= p;
                ll k = p_idx[pp];
              
                if (k < K) {
                    ll idx = k + N;
                    tree[idx] = i;
                    idx /= 2;
                    while (idx > 0) {
                        tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
                        idx /= 2;
                    }
                }
                pp *= p;
            }
        }

        for (auto& q : qu[i]) {
            ll k = q.first;
            ll a = q.second;
            if (k == 0) {
                valid[0] = true;
            } else {
                ll l = N;
                ll r = (k - 1) + N;
                ll mint = 1e10;

                while (l <= r) {
                    if (l % 2 == 1) 
                        mint = min(mint, tree[l++]);
                    if (r % 2 == 0) 
                        mint = min(mint, tree[r--]);
                    l /= 2;
                    r /= 2;
                }
                if (mint > a) 
                    valid[k] = true;
            }
        }
    }

    vector<ll> ans;
    for (ll k = 0; k < K; k++) {
        if (valid[k]) 
            ans.push_back(p_list[k]);
    }
    
    cout << ans.size() << "\n";

    for (ll i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i + 1 == ans.size() ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pc();
    
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

}