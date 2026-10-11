#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9 + 7;

void solve() {
    int64_t n;
    cin >> n;

    vector<int64_t> a(n);
    for (auto &l : a) cin >> l;

    int64_t m = a[n - 1];
    for (int i = 0; i < n; i++) {
        if (a[i] + a[n - 1 - i] != m) {
            cout << 0 << "\n";
            return;
        }
    }

    int64_t pm = n / 2;
    vector<int64_t> p(pm);
    for (int i = 0; i <pm; i++) 
        p[i] = a[i];
    

    unordered_set<int64_t> allow(a.begin(), a.end());

    for (int i = 1; i < pm; i++) {
        if (!allow.count(p[i] - p[i - 1])) {
            cout << 0 << "\n";
            return;
        }
    }

    int64_t ans = pm % MOD;
    for (int i = 0; i < pm - 1; i++) 
        ans = (ans * 2) % MOD;
    

    if (n % 2 != 0) 
        ans = (ans * 2) % MOD;

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t t;
    cin >> t;
    while (t--) solve();
}