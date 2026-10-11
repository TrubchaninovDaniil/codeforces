#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t x, y;
    cin >> x >> y;
    int64_t sum = x + y;
    int64_t ans = 0;
    
    for (int i = 30; i >= 0; i--) {
        if ((sum >> i) & 1) {
            if (ans + (1 << i) <= x) 
                ans += (1 << i);
        }
    }
    
    cout << sum << " " << x - ans << "\n";
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int64_t t;
    cin >> t;
    while (t--) solve();
}