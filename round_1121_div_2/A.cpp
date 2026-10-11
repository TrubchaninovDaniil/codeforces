#include <bits/stdc++.h>

using namespace std;

void solve() {
    
    int64_t n;
    cin >> n;

    vector<int64_t> p(n, 0);
    for (auto& e : p) cin >> e;
    
    vector<int64_t> o;

    for (int i = 0; i < p.size(); i++) {
        if ((i + 1) != p[i])
            o.push_back(p[i]);
    }

    bool ok = true;
    
    for (int i = 1; i < o.size(); i++) {
        if (o[i - 1] < o[i])
            ok = false;
    }

    if (ok) 
        cout << "YES" << "\n";
    else 
        cout << "NO" << "\n";

}
 
int main() {
    int64_t t;
    cin >> t;
    while (t--) solve();
}
