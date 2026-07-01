#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair

const ll inf = 1e18;

vector <int> used, sz;
vector <vector <int> > dp;

set <tuple <int, int, int> > st;

void solve();
void dfs(vector <vector <pii> > &, int);
void dfs2(vector <vector <pii> > &, int);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}

void solve() {
    int n, f;
    cin >> n >> f;
    f--;
    vector <vector <pii> > g(n);
    used.assign(n, 0);
    sz.assign(n, 1);
    st.clear();
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back(mp(v, w));
        g[v].push_back(mp(u, w));
    }
    dfs(g, f);
    for (int i = 0; i < n; i++) {
        used[i] = 0;
        //cout << i << " " << sz[i] << "\n";
    }
    dfs2(g, f);
    for (auto &[w, u, v] : st) {
        cout << u + 1 << " " << v + 1 << "\n";
    }
}

void dfs(vector <vector <pii> > &g, int v) {
    used[v] = 1;
    for (auto &[u, w] : g[v]) {
        if (!used[u]) {
            dfs(g, u);
            sz[v] += sz[u];
        }
    }
}

void dfs2(vector <vector <pii> > &g, int v) {
    used[v] = 1;
    for (auto &[u, w] : g[v]) {
        if (!used[u]) {
            int mult = 1;
            if (2 * sz[u] >= sz[v]) mult = 2;
            w *= mult;
            st.insert(make_tuple(-w, v, u));
            dfs2(g, u);
        }
    }
}