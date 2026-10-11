#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

bool k(ll u, ll v, ll d) {
    if (d == 0) 
        return true;
   
    cout << "? " << u << " " << v << " " << d << endl;
   
    ll res;
    cin >> res;
    if (res == -1) 
        exit(0); 
   
    return res == 1;
}

void solve() {
    ll n;
    cin >> n;

    ll u = 1;
    ll d1 = 0;

    for (ll i = 2; i <= n; i++) {
        while (k(1, i, d1 + 1)) {
            d1++;
            u = i;
        }
    }
    
    ll v = 1;
    ll d = d1;
    
    for (ll i = 1; i <= n; i++) {
        if (i == u) 
            continue;
        while (k(u, i, d + 1)) {
            d++;
            v = i;
        }
    }

    cout << "! " << u << " " << v << " " << d << endl;
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