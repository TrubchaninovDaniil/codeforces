#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int64_t sum = 0;
    int64_t max_val = 0;
    int64_t ans = 0;
    int64_t e = 0;
    int64_t contrib = 0;
};

int64_t n;
vector<int64_t> a;
vector<Node> tree;

pair<int64_t, int64_t> calc(int64_t v, int64_t l, int64_t r, int64_t s)
{
    if (tree[v].max_val == 0)
        return {0, s};
    
    if (s >= tree[v].max_val)
        return {0, s + tree[v].sum};
        
    if (l == r)
        return {1, tree[v].max_val};

    int mid = (l + r) / 2;
    int left = 2 * v;
    int right = 2 * v + 1;

    auto [lt, le] = calc(left, l, mid, s);

    if (lt > 0)
        return {lt + tree[v].contrib, tree[v].e};
    
    auto [rt, re] = calc(right, mid + 1, r, le);
    return {rt, re};
}

void push(int v, int l, int r)
{
    int mid = (l + r) / 2;
    int left = 2 * v;
    int right = 2 * v + 1;

    tree[v].sum = tree[left].sum + tree[right].sum;
    tree[v].max_val = max(tree[left].max_val, tree[right].max_val);

    if (tree[left].max_val == 0)
    {
        tree[v].ans = tree[right].ans;
        tree[v].e = tree[right].e;
        tree[v].contrib = 0;
        return;
    }
    if (tree[right].max_val == 0)
    {
        tree[v].ans = tree[left].ans;
        tree[v].e = tree[left].e;
        tree[v].contrib = 0;
        return;
    }

    auto [rt, re] = calc(right, mid + 1, r, tree[left].e);
    tree[v].contrib = rt;
    tree[v].ans = tree[left].ans + rt;
    tree[v].e = re;
}

void build(int v, int l, int r)
{
    if (l == r)
    {
        tree[v].sum = a[l];
        tree[v].max_val = a[l];
        tree[v].ans = 0;
        tree[v].e = a[l];
        tree[v].contrib = 0;
        return;
    }
    int64_t mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    push(v, l, r);
}

void dect(int v, int l, int r, int p)
{
    if (l == r)
    {
        tree[v].sum = 0;
        tree[v].max_val = 0;
        tree[v].ans = 0;
        tree[v].e = 0;
        tree[v].contrib = 0;
        return;
    }
    int64_t m = (l + r) / 2;
    if (p <= m)
        dect(2 * v, l, m, p);
    else
        dect(2 * v + 1, m + 1, r, p);
    
    push(v, l, r);
}

void solve()
{
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    vector<int64_t> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    

    tree.assign(4 * n + 1, Node());
    build(1, 1, n);

    vector<int64_t> ans;
    ans.reserve(n);

    ans.push_back(tree[1].ans);

    for (int i = 1; i < n; i++)
    {
        dect(1, 1, n, p[i]);
        ans.push_back(tree[1].ans);
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    
}