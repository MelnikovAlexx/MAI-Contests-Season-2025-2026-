#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e9, mod = inf + 7;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector <vector <pair <int, int> > > g(3001);
    vector <pair <int, int> > pairs;
    map <pair <int, int>, int> dc;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        dc[{u, v}] = i + 1;
        g[u].push_back({v, i + 1});
    }
    int f, a, b;
    cin >> f >> a >> b;
    g[0].push_back({a, -1});
    g[0].push_back({b, -1});
    queue <int> q;
    vector <int> p(3001, -1);
    vector <int> p2(3001, -1);
    vector <int> d(3001, inf);
    q.push(0);
    d[0] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto &[u, i] : g[v]) {
            if (d[u] > d[v] + 1) {
                d[u] = d[v] + 1;
                p[u] = v;
                p2[u] = i;
                q.push(u);
            }
        }
    }
    if (d[f] == inf) cout << "IMPOSSIBLE";
    else {
        vector <int> path;
        while (p2[f] != -1) {
            path.push_back(p2[f]);
            f = p[f];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << "\n";
        for (auto &x : path)
            cout << x << "\n";
    }
}

