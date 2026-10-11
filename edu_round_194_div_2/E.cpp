#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int64_t> P0(n + 1, 0);
    vector<int64_t> P1(n + 1, 0);
    vector<int64_t> P00(n + 1, 0);
    vector<int64_t> P11(n + 1, 0);
    vector<int64_t> P01(n + 1, 0);

    for (int i = 0; i < n; i++) {

        P0[i + 1] = P0[i] + (s[i] == '0' ? 1 : 0);
        P1[i + 1] = P1[i] + (s[i] == '1' ? 1 : 0);

        if (i > 0) {
            P00[i + 1] = P00[i] + (s[i - 1] == '0' && s[i] == '0' ? 1 : 0);
            P11[i + 1] = P11[i] + (s[i - 1] == '1' && s[i] == '1' ? 1 : 0);
            P01[i + 1] = P01[i] + (s[i - 1] == '0' && s[i] == '1' ? 1 : 0);
        }
    }

    for (int i = 0; i < q; i++) {
        
        int64_t l, r;
        cin >> l >> r;
        
        int64_t len = r - l + 1;
        
        int64_t c0 = P0[r] - P0[l - 1];
        int64_t c1 = P1[r] - P1[l - 1];
        int64_t c00 = 0, c11 = 0, c01 = 0;
        
        if (len > 1) {
            c00 = P00[r] - P00[l];
            c11 = P11[r] - P11[l];
            c01 = P01[r] - P01[l];
        }
        
        int64_t cc00 = c00 + (s[l - 1] == '0' && s[r - 1] == '0' ? 1 : 0);
        int64_t cc11 = c11 + (s[l - 1] == '1' && s[r - 1] == '1' ? 1 : 0);
        int64_t cc01 = c01 + (s[r - 1] == '0' && s[l - 1] == '1' ? 1 : 0);

        int64_t k1 = (c0 + 1) / 2;
        int64_t k2 = (c1 + 1) / 2;
        int64_t k3 = (cc00 + c1 + 2) / 3;
        int64_t k4 = (cc11 + c0 + 2) / 3;
        int64_t k5 = cc01;

        int64_t k = max({k1, k2, k3, k4, k5});
        
        cout << 4 * k - len << "\n";
    }
}