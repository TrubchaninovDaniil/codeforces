#include <iostream>
#include <vector>
using ll = long long;

ll gcd(ll a, ll b) {
    
    while (b) {
        a %= b;
        std::swap(a, b);
    }

    return a;
}


int main() {

    ll t;
    std::cin >> t;

    for (size_t i = 0; i < t; i++) {

        ll n, x, y;
        std::cin >> n >> x >> y;

        std::vector<ll> p(n, 0);
 
        for (auto & l : p)
            std::cin >> l;
            
        ll d = gcd(x, y);

        bool ok = true;

        for (ll i = 0; i < n; i++) {
            if ((p[i] % d) != ((i + 1) % d)) {
                ok = false;
            }
        }

        if (ok) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }

    }
}