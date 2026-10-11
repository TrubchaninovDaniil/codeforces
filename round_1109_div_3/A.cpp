#include <iostream>
#include <cmath>

using ld = long double;

int main() {
    ld t;
    std::cin >> t;

    for (size_t i = 0; i < t; i++) {
        int n;
        std::cin >> n;

        std::string s;
        std::cin >> s;
    
        ld longest_line = 0, line = 1;
        
        for (size_t i = 0; i < n - 1; i++) {
            if ((s[i] == s[i + 1]) && s[i] == '#') {
                line += 1;
            } else if (s[i] == '#' && s[i + 1] != '#')  {
                longest_line = std::max(longest_line, line);
                line = 1;
            } 
            continue;
        }

        longest_line = std::max(longest_line, line);

        bool has_line = false;

        for (size_t i = 0; i < n; i++) {
            if (s[i] == '#') {
                has_line = true;
            }
        }

        if (!has_line) {
            std::cout << 0 << '\n';
        } else {
            std::cout << std::ceil(longest_line / 2) << '\n';
        }

    }
}