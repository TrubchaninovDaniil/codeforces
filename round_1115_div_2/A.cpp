#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;

    map<ll, ll> freq;

    ll total_sum = 0;
    ll max_freq = 0;
    ll max_value = 0;

    for (size_t i = 0; i < n; i++) {
        ll a;
        cin >> a;
        freq[a]++;
        total_sum += a;

        if (freq[a] > max_freq) {
            max_freq = freq[a];
            max_value = a;
        }
    }

    ll others = n - max_freq;

    ll max_allowed = others + 2;

    if (max_allowed >= max_freq) {
        cout << total_sum << "\n";
    } else {
        ll excess = max_freq - max_allowed;
        cout << total_sum - (excess * max_value) << "\n";
    }

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