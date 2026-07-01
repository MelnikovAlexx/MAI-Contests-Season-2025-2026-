#include <bits/stdc++.h>
using namespace std;

//#define int long long
const int inf = 1e9, mod = inf + 7;


signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, s;
    cin >> n >> m >> s;
    vector <vector <pair <int, int> > > g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    s--;
    queue <pair <int, int> > q;
    vector <int> d(n, -inf);
    d[s] = inf;
    q.push({s, inf});
    while (!q.empty()) {
        int v = q.front().first;
        q.pop();
        for (auto &[u, w] : g[v]) {
            if (min(d[v], w) > d[u]) {
                d[u] = min(d[v], w);
                q.push({u, d[u]});
            }
        }
    }
    for (auto &x : d) {
        if (x == inf) cout << "-1 ";
        else if (x == -inf) cout << "0 ";
        else cout << x << " ";
    }
}
