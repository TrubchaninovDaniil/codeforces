#include <bits/stdc++.h>

using namespace std;

void solve() {
    int64_t n;
    cin >> n;

    vector<int64_t> a(n + 1);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];

    vector<int> d(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int64_t l = i * a[i];
        int64_t r = (l + i - 1);

        if (l < n) {
            d[l]++;
            if (r + 1 < n) {
                d[r + 1]--;
            }
        }
    }

    vector<int64_t> b;
    int64_t fb = 0;

    for (int i = 0; i < n; i++) {
        fb += d[i];
        if (fb == 0)
            b.push_back(i);
    }

    cout << b.size() << "\n";
    for (auto& l : b) cout << l << " ";
    cout << "\n";
    
}

int main() {
    int64_t t;
    cin >> t;
    while (t--) solve();

}

