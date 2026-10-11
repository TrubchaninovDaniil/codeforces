#include <bits/stdc++.h>

using namespace std;

void solve() {
    int64_t n;
    cin >> n;
    
    vector<int64_t> a(n);
    int64_t zt = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) 
            zt++;
    }
    
    if (zt < 2) {
        cout << -1 << "\n";
    } else {
        int64_t operations = 0;
        if (a[0] == 1) operations++;
        if (a[n - 1] == 1) operations++;
        cout << operations << "\n";
    }
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