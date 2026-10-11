#include <bits/stdc++.h>

using namespace std;

void dfs(int64_t u, int64_t p, int64_t d, 
         vector<vector<pair<int64_t, int64_t>>>& a,
         vector<bool>& vis, 
         vector<int64_t>& depth, 
         vector<int64_t>& parent_node, 
         vector<int64_t>& parent_edge, 
         vector<int64_t>& edgesb) {

    vis[u] = true;
    depth[u] = d;
    for (auto& edge : a[u]) {
        int64_t v = edge.first;
        int64_t id = edge.second;
        
        if (v == p) 
            continue;
        
        if (vis[v]) {
            if (depth[v] < depth[u]) {
                edgesb.push_back(id);
            }
        } else {
            parent_node[v] = u;
            parent_edge[v] = id;
            dfs(v, u, d + 1, a, vis, depth, parent_node, parent_edge, edgesb);
        }
    }
}

void solve() {
    int64_t n, m;
    cin >> n >> m;

    vector<int64_t> u(m), v(m);
    vector<vector<pair<int64_t, int64_t>>> a(n);

    for (int i = 0; i < m; i++) {

        cin >> u[i] >> v[i];
        u[i]--; v[i]--;

        a[u[i]].push_back({v[i], i});
        a[v[i]].push_back({u[i], i});
    }

    int64_t k = m - n + 1;

    if (k <= 0) {
        cout << "NO\n";
        return;
    }

    vector<bool> vis(n, false);
    vector<int64_t> depth(n, 0);
    vector<int64_t> parent_edge(n, -1);
    vector<int64_t> parent_node(n, -1);
    vector<int64_t> edgesb;

    dfs(0, -1, 0, a, vis, depth, parent_node, parent_edge, edgesb);

    vector<vector<int64_t>> fc;

    for (int64_t id : edgesb) {

        vector<int64_t> esc;
        esc.push_back(id);

        int64_t cur = u[id];
        int64_t target = v[id];

        if (depth[cur] < depth[target]) 
            swap(cur, target);
        
            while (cur != target) {

            esc.push_back(parent_edge[cur]);
            cur = parent_node[cur];
        }
        
        fc.push_back(esc);
    }

    vector<int64_t> edgeMask(m, 0);
    for (int i = 0; i < fc.size(); i++) {
        for (int64_t id : fc[i]) 
            edgeMask[id] |= (1 << i);
        
    }

    vector<int64_t> degree(n);
    vector<bool> ie(m);
    vector<bool> vv(n);
    vector<bool> vg(n);

    bool found = false;
    int64_t num_masks = 1 << fc.size();
    
    for (int mask = 1; mask < num_masks; ++mask) {
        int64_t edge_cnt = 0;
        int64_t Fvertex = -1;
        
        for (int i = 0; i < n; ++i) degree[i] = 0;
        
        for (int id = 0; id < m; ++id) {
            if (__builtin_parity(edgeMask[id] & mask)) {

                ie[id] = true;
                degree[u[id]]++;
                degree[v[id]]++;
                edge_cnt++;
                
                if (Fvertex == -1) 
                    Fvertex = u[id];
            } else {
                ie[id] = false;
            }
        }
        
        if (edge_cnt == 0) 
            continue;
        
        bool is_s_c = true;
        for (int i = 0; i < n; ++i) {
            if (degree[i] != 0 && degree[i] != 2) {
                is_s_c = false;
                break;
            }
        }
        
        if (!is_s_c) 
            continue;
        
        for (int i = 0; i < n; ++i) 
            vv[i] = false;
        
        int64_t visited_edges = 0;
        
        queue<int64_t> q;
        q.push(Fvertex);
        vv[Fvertex] = true;
        
        while (!q.empty()) {

            int curr = q.front();
            q.pop();

            for (auto& edge : a[curr]) {
                int64_t v = edge.first;
                int64_t id = edge.second;
                if (ie[id]) {
                    visited_edges++;
                    if (!vv[v]) {
                        vv[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        
        if (visited_edges / 2 != edge_cnt) 
            continue;
        
        for (int i = 0; i < n; ++i) 
            vg[i] = false;
        
        int64_t c_cnt = 0;
        queue<int> qg;
        qg.push(0);
        vg[0] = true;
        
        while (!qg.empty()) {

            int curr = qg.front();
            qg.pop();
            c_cnt++;

            for (auto& edge : a[curr]) {

                int64_t v = edge.first;
                int64_t id = edge.second;

                if (!ie[id] && !vg[v]) {
                    vg[v] = true;
                    qg.push(v);
                }
            }
        }
        
        if (c_cnt == n) {
            found = true;
            break;
        }
    }

    if (found) 
        cout << "YES\n";
    else 
        cout << "NO\n";
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