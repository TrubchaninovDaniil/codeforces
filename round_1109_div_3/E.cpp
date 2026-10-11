#include <iostream>
#include <vector>
#include <cmath>

using ll = long long;
using v = std::vector<ll>;

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll t;
    std::cin >> t;

    for (size_t i = 0; i < t; i++) {
        ll n, q;
        std::cin >> n >> q;

        std::string a;
        v d(n - 1, 0);
        v pref_sum_d(n, 0);

        std::cin >> a;
      
        for (size_t j = 0; j < n - 1; j++) {
            if (a[j] == a[j + 1]) {
                d[j] = 1;
            } else {
                d[j] = 0;
            }
        }

        for (int w = 1; w < n; w++) {
            if (d[w - 1] == 1) {
                pref_sum_d[w] = pref_sum_d[w - 1] + 1;
            } else {
                pref_sum_d[w] = pref_sum_d[w - 1];
            }
        }
        
        for (size_t j = 0; j < q; j++) {

            ll l, r, k;
            std::cin >> l >> r >> k;

            l--, r--; 
            ll sum = pref_sum_d[r] - pref_sum_d[l];
       
            if (k >= (sum + 1) / 2) {
                std::cout << "YES\n";
            } else{
                std::cout << "NO\n";
            }
        }
    }
}