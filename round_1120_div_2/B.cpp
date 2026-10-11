#include <bits/stdc++.h>

using namespace std;

void solve() {
    int64_t n, k;
    cin >> n >> k;

    if (k < n || k > 2 * n - 1) {
        cout << -1 << "\n";
        return;
    }

    int64_t c = 2 * n - k;
    
    vector<vector<int64_t>> a(n, vector<int64_t>(n, 0));
    int64_t xt = 1;

    for (int i = 0; i < c; i++) {
        a[i][i] = xt++;
    }

    for (int i = c; i < n; i++) {
        a[i][0] = xt++;
        a[0][i] = xt++;

    }

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            if (a[i][j] == 0) 
                a[i][j] = xt++;
        
    

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t t;
    cin >> t;
    while (t--) solve();
    
}