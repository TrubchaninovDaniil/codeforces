#include <bits/stdc++.h>

using namespace std;

void solve() {
    int64_t n, m;
    cin >> n >> m;

    vector<int64_t> a(n, 0);
    for (auto &e : a) cin >> e;

    priority_queue<int64_t> q;
    int64_t heap_sum = 0, answer_sum = -4e18;

    if (m == 1) {
        int64_t mx = -4e18;
        for (auto& x : a) mx = std::max(mx, x);
        cout << mx << '\n';
        return;
    }

    for (int i = 1; i < n; i++) {
        heap_sum += a[i - 1];
        q.push(a[i - 1]);

        if (i >= m) {
            int64_t bad = q.top();
            q.pop();
            heap_sum -= bad;
        }

        if (i >= m - 1) 
            answer_sum = max(answer_sum, (m * a[i]) - heap_sum);
    }

    std::cout << answer_sum << "\n";
    
}

int main() {
    int64_t t;
    cin >> t;
    while (t--) solve();
}