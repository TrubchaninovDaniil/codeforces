#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

void solve() {
    ll n;
    cin >> n;
    
    string s;
    cin >> s;
    
    ll c0 = 0, c1 = 0;

    for (size_t i = 0; i < n; i++) {
        if (s[i] == '1')
            c1++;
        if (s[i] == '0')
            c0++;
    }

    if (abs(c1 - c0) > 2) {
        cout << -1 << "\n";
        return;
    }

    string sc;
    sc += s[0];
    for (size_t i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            sc += s[i];
        }
    }

    ll b0 = 0, b1 = 0; 

    for (size_t i = 0; i < sc.size(); i++) {
        if (sc[i] == '0')
            b0++;
        if (sc[i] == '1') 
            b1++;
    }

    ll d0 = c0 - b0, d1 = c1 - b1;

    while (d0 > d1 + 1) {
        d1++;
    }
    
    while (d1 > d0 + 1) {
        d0++;
    }
    
    cout << d1 + d0 << "\n"; 
}

int main() {
    ll t;
    cin >> t;
    while (t--) 
        solve();
}