#include <bits/stdc++.h>

using namespace std;

void solve() {
    int64_t x, y, k;
    cin >> x >> y >> k;
    
    int64_t d = y - x;
    int64_t ans = 0;
    
    int64_t ed = x - 1 + k;
    
    int64_t lim = min(d, ed);
    
    for (int64_t i = x; i <= lim; i++) 
        ans += (d % i);
        
    if (ed > d) {
        int64_t start = max(d + 1, x);
        int64_t c = ed - start + 1;
        
        if (c > 0) 
            ans += c * d;
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int64_t t;
    cin >> t;
    while (t--) solve();
}