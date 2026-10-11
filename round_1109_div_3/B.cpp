#include <iostream>
#include <vector>

using ll = long long;

int main() {
    ll t;
    std::cin >> t;

    for (size_t i = 0; i < t; i++) {
        
        ll n;
        std::cin >> n;

        std::vector<ll> a(n, 0);

        for (size_t i = 0; i < n; i++)
            std::cin >> a[i];

        bool is_neat = true;
        ll cur = 0;

        for (ll i = 0; i < n; i++) {
            cur += a[i];
            ll need = (i + 1) * (i + 2) / 2;
            if (cur < need) {
                is_neat = false;
            }
        }

        if (is_neat) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}