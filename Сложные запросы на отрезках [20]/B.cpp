#include <bits/stdc++.h>
using namespace std;

struct segtree
{
    vector <long long> tree;
    int sz;

    long long NO_OP = LLONG_MIN;

    void init(int n)
    {
        sz = 1;
        while (sz <= n) sz <<= 1;
        tree.assign(2 * sz + 1, NO_OP);
    }

    void build(vector <long long> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size())
                tree[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, x * 2 + 1, lx, m);
        build(a, x * 2 + 2, m, rx);
    }

    void build(vector <long long> &a) {
        init(a.size());
        build(a, 0, 0, sz);
    }

    void propagate(int x, int lx, int rx)
    {
        if (tree[x] == NO_OP || (rx - lx == 1)) return;
        tree[x * 2 + 1] = tree[x];
        tree[x * 2 + 2] = tree[x];
        tree[x] = NO_OP;
    }


    void set(int l, int r, int val, int x, int lx, int rx)
    {
        propagate(x, lx, rx);
        if (l >= rx || r <= lx) return;
        if (lx >= l && rx <= r)
        {
            tree[x] = val;
            return;
        }
        int m = (lx + rx) / 2;
        set(l, r, val, x * 2 + 1, lx, m);
        set(l, r, val, x * 2 + 2, m, rx);
    }


    void set(int l, int r, int val)
    {
        set(l, r, val, 0, 0, sz);
    }


    long long find(int v, int x, int lx, int rx)
    {
        propagate(x, lx, rx);
        if (rx - lx == 1) {
            return tree[x];
        }
        int m = (lx + rx) / 2;
        if (v < m)
            return find(v, x * 2 + 1, lx, m);
        else
            return find(v, x * 2 + 2, m, rx);
    }


    long long find(int v)
    {
        return find(v, 0, 0, sz);
    }
};


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n;
    vector <long long> a(n);
    for (auto &x : a) cin >> x;
    segtree st;
    st.build(a);
    cin >> m;
    while (m--)
    {
        int c; cin >> c;
        if (c == 0)
        {
            int l, r, v;
            cin >> l >> r >> v;
            l--;
            st.set(l, r, v);
        }
        else
        {
            int x; cin >> x;
            cout << st.find(x - 1) << "\n";
        }
    }
}
