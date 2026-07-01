#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair

const ll inf = 1e18;

void solve();

struct segtree{
    vector <ll> tree;
    int size;

    void combine(int x) {
        tree[x] = __gcd(tree[x * 2 + 1], tree[x * 2 + 2]);
    }

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size - 1, 0);
    }

    void build(vector <ll> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size())
                tree[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, x * 2 + 1, lx, m);
        build(a, x * 2 + 2, m, rx);
        combine(x);
    }

    void build(vector <ll> &a) {
        init(a.size());
        build(a, 0, 0, size);
    }

    void set(int i, ll v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            set(i, v, x * 2 + 1, lx, m);
        else
            set(i, v, x * 2 + 2, m, rx);
        combine(x);
    }

    void set(int i, ll v) {
        set(i, v, 0, 0, size);
    }

    ll op(int l, int r, int x, int lx, int rx) {
        if (r <= lx || l >= rx)
            return 0;
        if (l <= lx && rx <= r)
            return tree[x];
        int m = (lx + rx) / 2;
        ll res1 = op(l, r, x * 2 + 1, lx, m);
        ll res2 = op(l, r, x * 2 + 2, m, rx);
        return __gcd(res1, res2);
    }

    ll op(int l, int r) {
        return op(l, r, 0, 0, size);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--)
        solve();
    return 0;
}

void solve() {
    int n, m, c, i, v, l, r;
    cin >> n;
    vector <ll> a(n);
    for (auto &x : a) cin >> x;
    segtree st;
    st.build(a);
    cin >> m;
    while (m--) {
        cin >> l >> r;
        l--;
        cout << st.op(l, r) << "\n";
    }
}
