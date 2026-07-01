#include <bits/stdc++.h>
using namespace std;

#define int long long

struct segtree
{
    vector <int> tree;
    int sz;

    void init(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        tree.assign(2 * sz - 1, 0);
    }

    void build(vector <int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size())
                tree[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, x * 2 + 1, lx, m);
        build(a, x * 2 + 2, m, rx);
        tree[x] = tree[x * 2 + 1] + tree[x * 2 + 2];
    }

    void build(vector <int> &a) {
        init(a.size());
        build(a, 0, 0, sz);
    }

    void set(int p, int v, int x, int lx, int rx) {
        if (rx - lx == 1) 
        {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (p < m)
            set(p, v, x * 2 + 1, lx, m);
        else 
            set(p, v, x * 2 + 2, m, rx);
        tree[x] = tree[x * 2 + 1] + tree[x * 2 + 2];
    }

    void set(int p, int v) {
        set(p, v, 0, 0, sz);
    }

    int sum(int l, int r, int x, int lx, int rx) {
        if (l >= rx || r <= lx) return 0;
        if (l <= lx && rx <= r) return tree[x];
        int m = (lx + rx) / 2;
        int r1 = sum(l, r, x * 2 + 1, lx, m);
        int r2 = sum(l, r, x * 2 + 2, m, rx);
        return r1 + r2;
    }

    int sum(int l, int r) {
        return sum(l, r, 0, 0, sz);
    }
};


signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n), used(n, 0);
    for (auto &x : a) cin >> x;
    segtree st;
    st.build(used);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += st.sum(a[i] - 1, n);
        st.set(a[i] - 1, 1);
    }
    cout << ans;
}
