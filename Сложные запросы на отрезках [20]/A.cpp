#include <bits/stdc++.h>
using namespace std;


struct segtree {

    struct node {
        long long sum;
        long long len;
        long long add;
    };


    node combine(node a, node b) {
        return {
            a.sum + b.sum,
            a.len + b.len,
            0
        };
    }

    vector <node> tree;
    int size;


    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size - 1, {0, 0, 0});
    }

    void build(vector <long long> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size())
                tree[x] = {a[lx], 1, 0};
            else tree[x] = {0, 1, 0};
            return;
        }
        int m = (lx + rx) / 2;
        build(a, x * 2 + 1, lx, m);
        build(a, x * 2 + 2, m, rx);
        tree[x] = combine(tree[x * 2 + 1], tree[x * 2 + 2]);
    }

    void build(vector <long long> &a) {
        init(a.size());
        build(a, 0, 0, size);
    }

    void set(int l, int r, int val, int x, int lx, int rx) {
        if (rx <= l || lx >= r) return;
        if (l <= lx && rx <= r) {
            tree[x].sum += (val * tree[x].len);
            tree[x].add += val;
            return;
        }
        int m = (lx + rx) / 2;
        set(l, r, val, x * 2 + 1, lx, m);
        set(l, r, val, x * 2 + 2, m, rx);
        tree[x].sum = tree[x * 2 + 1].sum + tree[x * 2 + 2].sum + tree[x].add * tree[x].len;
    }

    long long get(int l, int r, int x, int lx, int rx) {
        if (rx <= l || lx >= r) return 0LL;
        if (l <= lx && rx <= r) return tree[x].sum;
        int m = (lx + rx) / 2;
        long long sum1 = get(l, r, x * 2 + 1, lx, m);
        long long sum2 = get(l, r, x * 2 + 2, m, rx);
        return sum1 + sum2 + tree[x].add * (min(rx, r) - max(lx, l));
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q, l, r, v;
    cin >> n;
    vector <long long> a(n);
    for (auto &x: a) cin >> x;
    segtree st;
    st.build(a);
    cin >> q;
    while (q--) {
        cin >> l >> r >> v;
        l--;
        st.set(l, r, v, 0, 0, st.size);
        cout << st.get(l, r, 0, 0, st.size) << "\n";
    }
}