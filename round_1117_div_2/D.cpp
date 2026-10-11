#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve()
{
    ll s, q;
    cin >> s >> q;

    vector<pair<ll, ll>> areas_coordinate;

for (size_t i = 1; i * i <= s; i++)
    {
        if (s % i == 0)
        {
            ll A = i;
            ll B = s / i;
            areas_coordinate.push_back({A, B});
            if (A != B) { 
                areas_coordinate.push_back({B, A});
            }
        }
    }
    sort(areas_coordinate.begin(), areas_coordinate.end(), [](const auto &a, const auto &b)
         { return a.first < b.first; });
    ll k = areas_coordinate.size();

    vector<ll> pref_area(k);    
    ll prev_A = 0.0;
    for (size_t i = 0; i < k; i++) {
        ll width = areas_coordinate[i].first - prev_A;
        ll height = areas_coordinate[i].second;
        pref_area[i] = width * height + (i > 0 ? pref_area[i - 1] : 0);
        prev_A = areas_coordinate[i].first;
    }

    while (q--) {
        ll x, y;
        cin >> x >> y;

        ll idx = lower_bound(areas_coordinate.begin(), areas_coordinate.end(), make_pair(x, 0LL)) - areas_coordinate.begin();
    
        ll p = -1;
        ll low = 0, high = k - 1;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (areas_coordinate[mid].second >= y) {
                p = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        ll ans = 0;

        ll capped_limit = min(idx - 1, p);
        if (capped_limit >= 0) {
            ans += areas_coordinate[capped_limit].first * y;
        }

        if (idx - 1 > p) {
            ll full_uncapped = pref_area[idx - 1] - (p >= 0 ? pref_area[p] : 0);
            ans += full_uncapped;
        }

        if (idx < k) {
            ll left_A = (idx > 0) ? areas_coordinate[idx - 1].first : 0;
            ll partial_width = min(x, areas_coordinate[idx].first) - left_A;
            if (partial_width > 0) {
                ans += partial_width * min(y, areas_coordinate[idx].second);
            }
        }

        cout << ans << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}