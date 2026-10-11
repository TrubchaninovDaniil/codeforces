#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n, 0);
    vector<ll> b(m, 0);

    for (auto &l : a) cin >> l;
    for (auto &l : b) cin >> l;

    if (a[0] + n - 1 >= b[0] + m - 1) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }
}

int main () {
    ll t;
    cin >> t;

    while(t--) {
        solve();
    }
}