#include <bits/stdc++.h>
using namespace std;

int g(int64_t x) {
    return (x % 2 + 2) % 2;
}

void process(int64_t il, int64_t ir, char c, int64_t& minv, int64_t& maxv) {
    if (il > ir) return;
    if (c == '+') {
        il = max((int64_t) 1, il);
    } else if (c == '-') {
        ir = min((int64_t) -1, ir);
    } else {
        il = max((int64_t) 0, il);
        ir = min((int64_t) 0, ir);
    }
    if (il <= ir) {
        minv = min(minv, il);
        maxv = max(maxv, ir);
    }
}

bool f(int64_t k, string& s) {
    if (k == 1) {
        
        int64_t L = 0, R = 0;
        for (int i = 0; i < s.length(); i++) {

            int64_t nL = L - 1;
            int64_t nR = R + 1;
            
            int p = (i + 1) % 2;
            char c = s[i];
            if (c == '+') {
                nL = max((int64_t) 1, nL);
                if (g(nL) != p) nL++;

            } else if (c == '-') {
                nR = min((int64_t) -1, nR);
                if (g(nR) != p) nR--;

            } else {
                if (0 < nL || 0 > nR || p != 0) return false;
                nL = 0; nR = 0;
            }
            if (nL > nR) return false;
            L = nL; R = nR;
        }
        return true;
    }

    int64_t L = 0, R = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        int64_t minv = 1e18;
        int64_t maxv = -1e18;

        if (L == R) {
            process(L - k, L - 1, c, minv, maxv);
            process(L + 1, L + k, c, minv, maxv);
        } else {
            process(L - k, R + k, c, minv, maxv);
        }

        if (minv > maxv) 
            return false;
        L = minv;
        R = maxv;
    }
    return true;
}

void solve() {
    int64_t n;
    cin >> n;

    string s;
    cin >> s;

    int64_t low = 1, high = n;
    int64_t ans = -1;
   
    while (low <= high) {

        int64_t mid = low + (high - low) / 2;
        if (f(mid, s)) {
            ans = mid;
            high = mid - 1;
        } else 
            low = mid + 1;
        
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int64_t t;
    cin >> t;
    
    while (t--) {
        solve();
    }

}