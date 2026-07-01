#include <bits/stdc++.h>
using namespace std;

//#define int long long
const int inf = 1e9, mod = inf + 7;


signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, s, f;
    cin >> n >> m >> s >> f;
    s--; f--;
    vector <vector <pair <int, int> > > g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back({v, 0});
        g[v].push_back({u, 1});
    }
    priority_queue <pair<int, int>> q;
    vector <int> d(n, inf);
    q.push({s, 0});
    d[s] = 0;
    while (!q.empty()) {
        int v = q.top().first;
        q.pop();
        for (auto &[u, w] : g[v]) {
            if (d[u] > d[v] + w) {
                d[u] = d[v] + w;
                q.push({u, -d[u]});
            }
        }
    }
    cout << d[f];
}
