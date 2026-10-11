#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;
    
    vector<ll> count(m + 1, 0);
    vector<ll> pref(m + 1, 0);

    for (size_t i = 0; i < n; i++) {
        ll a;
        cin >> a;
        count[a]++;
    }

    for (size_t i = 1; i <= m; i++) 
        pref[i] = pref[i - 1] + count[i];
    

    ll max_car = 0;
    
    for (size_t i = 1; i <= m; i++) {
        ll cur = count[i];           
        cur += (n - pref[i]);         
        
        if (2 * i <= m) 
            cur += count[2 * i];      
        
        max_car = max(max_car, cur);
    }

    cout << max_car << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
}