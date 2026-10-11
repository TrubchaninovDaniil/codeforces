#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (size_t i = 0; i < n; i++) 
        cin >> a[i];
    

    if (n == 1) {
        cout << a[0] << "\n";
    } else {
        cout << gcd(a[0], a[n - 1]) << "\n";
    }
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