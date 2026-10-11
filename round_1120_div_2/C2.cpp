#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9 + 7;

void solve() {

    int64_t n;
    cin >> n;
    
    vector<int64_t> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int64_t> d(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int64_t l = i * a[i];
        int64_t r = l + i - 1;
        if (l < n) {
            d[l]++;
            if (r + 1 < n) d[r + 1]--;
        }
    }

    vector<int64_t> allow;
    int64_t fb = 0;
    for (int i = 0; i < n; i++) {
        fb += d[i];
        if (fb == 0) 
            allow.push_back(i);
    }

    vector<int64_t> ml(allow.size() + 2, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < a[i]; j++) {
            int64_t l = i * j;
            int64_t r = l + i - 1;
            
            if (l >= n) break; 
            r = min(r, n - 1);

            auto it1 = lower_bound(allow.begin(), allow.end(), l);
            auto it2 = upper_bound(allow.begin(), allow.end(), r);
            
            if (it1 != it2) {

                int64_t l_index = distance(allow.begin(), it1) + 1; 
                int64_t r_index = distance(allow.begin(), it2);     
                
                ml[r_index] = max(ml[r_index], l_index);
            }
        }
    }

    for (int i = 1; i <= allow.size() + 1; i++) 
        ml[i] = max(ml[i], ml[i - 1]);
    

    vector<int64_t> dp(allow.size() + 2, 0);
    vector<int64_t> sum_dp(allow.size() + 2, 0);
    
    dp[0] = 1; 
    sum_dp[0] = 1;

    int64_t m = allow.size();

    for (int i = 1; i <= m + 1; i++) {
        int64_t l = ml[i - 1];
        
        if (l <= i - 1) {
            int64_t w = sum_dp[i - 1];
            if (l > 0) 
                w = (w - sum_dp[l - 1] + MOD) % MOD;
            dp[i] = w;
        } else 
            dp[i] = 0; 
        
        sum_dp[i] = (sum_dp[i - 1] + dp[i]) % MOD;
    }

    cout << dp[m + 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int64_t t;
    cin >> t;
    
    while (t--) solve();
}