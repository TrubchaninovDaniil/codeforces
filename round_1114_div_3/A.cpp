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
    ll a, b, c;
    std::cin >> a >> b >> c;

    ll count = 0;

    while (true) {
        if (a > b)
            swap(a, b);
        if (b > c)
            swap(b, c);
        if (a > b)
            swap(a, b);

        if (a == c || a == b || b == c)
            break;
        
        c--;
        a++;
        count += 1;
    }

    std::cout << count << "\n";
}}