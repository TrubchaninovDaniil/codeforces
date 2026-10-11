#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
        
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    ll t;
    cin >> t;
    
    for (size_t i = 0; i < t; i++) {
        bool ok = true;
        
        ll n, m;
        cin >> n >> m;

        vector<std::string> s1(n);
        vector<std::string> s2(m);

        for (size_t i = 0; i < n; i++)
            std::cin >> s1[i];

        for (size_t i = 0; i < m; i++)
            std::cin >> s2[i];

        vector<char> letters;

        for (size_t i = 0; i < n; i++) {
            letters.push_back(toupper(s1[i][0]));
        } 

        std::vector<ll> total(m, 0);

        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < s2[i].size(); j++) {
                for (size_t k = 0; k < letters.size(); k++) {
                    if (s2[i][j] == letters[k]) {
                        total[i]++;
                        break;
                    }
                }
                letters.push_back(s2[i][0]);
            }
        }


        for (size_t i = 0; i < total.size(); i++) {
            if (s2[i].size() != total[i]) {
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