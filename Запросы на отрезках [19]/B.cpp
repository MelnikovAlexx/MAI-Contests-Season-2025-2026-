#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair

const ll inf = 1e18;

void solve();

struct Node{
    ll max, ind, cnt;
};

struct segtree{
    vector<Node>tree;
    int sz;

    Node combine(int x) {
        Node l = tree[x * 2 + 1];
        Node r = tree[x * 2 + 2];
        if (l.max == r.max) 
            return {l.max, min(l.ind, r.ind), l.cnt + r.cnt};
        if (l.max > r.max) 
            return {l.max, l.ind, l.cnt};
        return {r.max, r.ind, r.cnt};
    }

    Node combine(Node l, Node r) {
        if (l.max == r.max) 
            return {l.max, min(l.ind, r.ind), l.cnt + r.cnt};
        if (l.max > r.max) 
            return {l.max, l.ind, l.cnt};
        return {r.max, r.ind, r.cnt};
    }

    void init(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        tree.assign(2 * sz - 1, {-inf, inf, 0});
    }

    void build(vector <ll> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size())
                tree[x] = {a[lx], lx, 1};
            return;
        }
        int m = (lx + rx) / 2;
        build(a, x * 2 + 1, lx, m);
        build(a, x * 2 + 2, m, rx);
        tree[x] = combine(x);
    }

    void build(vector <ll> &a) {
        init(a.size());
        build(a, 0, 0, sz);
    }

    Node op(int l, int r, int x, int lx, int rx) {
        if (l >= rx || r <= lx)
            return {-inf, inf, 0};
        if (l <= lx && rx <= r)
            return tree[x];
        int m = (lx + rx) / 2;
        Node res1 = op(l, r, x * 2 + 1, lx, m);
        Node res2 = op(l, r, x * 2 + 2, m, rx);
        return combine(res1, res2);
    }

    Node op(int l, int r) {
        return op(l, r, 0, 0, sz);
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
        Node res = st.op(l, r);
        cout << res.max << " " << res.ind + 1 << " " << res.cnt << "\n";
    }
}
