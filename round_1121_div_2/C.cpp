#include <bits/stdc++.h>

using namespace std;
constexpr int64_t MOD = 998244353;

int64_t power(int64_t base, int64_t exp) {
    int64_t res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    int64_t n;
    cin >> n;

    vector<int64_t> a(n, 0);
    for (auto& e : a) cin >> e;

    sort(a.begin(), a.end());

    int64_t f = 1;
    for (int k = 1; k <= n - 1; k++) {
        f = (f * k) % MOD;
    }

    vector<int64_t> suff(n, 0);

    suff[n - 1] = a[n - 1] % MOD;

    for (int i = n - 2; i >= 0; i--) {
        suff[i] = (suff[i + 1] + a[i] % MOD) % MOD;
    }
    
    int64_t ans_sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int64_t ways = (f * power(n - 1 - i, MOD - 2)) % MOD;
        int64_t parent_contrib = (ways * suff[i + 1]) % MOD;
        int64_t child_contrib = (f * (a[i] % MOD)) % MOD;

        int64_t term = (parent_contrib - child_contrib) % MOD;
        
        if (term < 0) 
            term += MOD;

        ans_sum = (ans_sum + term) % MOD;
    }
    
    cout << ans_sum << "\n";

}

int main() {
    int64_t t;
    cin >> t;
    while (t--) solve();
}

