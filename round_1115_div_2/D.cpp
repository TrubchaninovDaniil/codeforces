#include <bits/stdc++.h>

using namespace std;

void solve() {
    int64_t n;
    cin >> n;

    vector<int64_t> a(n, 0);

    for (auto& l : a) cin >> l;

    vector<int64_t> d(n - 1, 0);
    for (int i = 0; i < a.size() - 1; i++) {
        d[i] = a[i + 1] - a[i]; 
    }
    
    int64_t L = 0;
    for (int R = 1; R <= n - 1; R++) {
        if (R == n - 1 || abs(d[R] % 2) != abs(d[R - 1] % 2)) {
            sort(d.begin() + L, d.begin() + R);
            L = R; 
        }
    }

    for (int i = 1; i < n; i++) 
        a[i] = a[i - 1] + d[i - 1];

    for (auto& l : a) cout << l << " ";
    cout << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t t;
    cin >> t;
    while (t--) {
        solve();
    }
} 