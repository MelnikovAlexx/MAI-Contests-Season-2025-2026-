#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e9, mod = inf + 7;

void solve() {
    int n, m, k, ds;
    cin >> n >> m >> k >> ds;
    vector <vector <pair <int, int> > > g(n + 1);
    int asylum[k];
    for (int i = 0; i < k; i++) {
        cin >> asylum[i]; asylum[i]--;
        g[n].push_back({asylum[i], 0});
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[v].push_back({u, w});
    }
    priority_queue <pair <int, int> > q;
    vector <int> d(n + 1, inf);
    d[n] = 0;
    q.push({n, 0});
    while (!q.empty()) {
        int v = q.top().first, w = -q.top().second;
        q.pop();
        if (w > d[v]) continue;

        for (auto &[u, w] : g[v]) {
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                q.push({u, -d[u]});
            }
        }
    }
    sort(asylum, asylum + k);
    for (int i = 0; i < n; i++)
        if (d[i] <= ds) cout << i + 1 << " ";
    cout << "\n";
}


signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

