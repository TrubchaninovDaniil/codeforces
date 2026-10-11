#include <bits/stdc++.h>

using namespace std;

void solve() {
    
    int64_t n;
    cin >> n;

    vector<int64_t> s(n, 0);

    for (auto &l : s) cin >> l;

    int64_t num0 = 0, num1 = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 0)
            num0++;
        if (s[i] == 1)
            num1++;
    }

    if (num1 >= num0) {
        cout << "Bessie" << "\n";
    } else {
        cout << "Elsie" << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int64_t t;
    cin >> t;
    while (t--) solve();
    
}