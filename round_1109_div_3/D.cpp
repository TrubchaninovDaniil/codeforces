#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

int main() {

    ll t;
    std::cin >> t;

    for (ll i = 0; i < t; i++) {
        ll n, m;
        std::cin >> n >> m;
        
        std::vector<ll> prod(n, 0);
        std::vector<ll> motiv(m, 0);

        for (size_t i = 0; i < n; i++)
            std::cin >> prod[i];
        
        for (size_t i = 0; i < m; i++)
            std::cin >> motiv[i];
        
        ll best_ans = 0;

        std::sort(motiv.begin(), motiv.end());

        for (ll i = 0; i < m; i++) {
            motiv[i]--;
        }
        
        std::vector<ll> ans;

        ll past_index = 0;
        for (ll i = 0; i < m; i++) {
            ll m_index = motiv[i];

            ll sum = 0, negative_sum = 0;

            for (ll j = past_index; j <= m_index; j++) {
                sum += prod[j];
            }

            for (ll j = past_index; j <= m_index; j++) {
                negative_sum += prod[j] * (-1);
            }

            ans.push_back(std::max(sum, negative_sum));
            
            past_index = m_index + 1;
        }

        if (past_index != n) {
            for (ll i = past_index; i < n; i++) {
                ans.push_back(prod[i]);
            }
        }
 
        for (ll i = 0; i < ans.size(); i++) {
            best_ans += ans[i];
        }

        std::cout << best_ans << "\n";
    }
}