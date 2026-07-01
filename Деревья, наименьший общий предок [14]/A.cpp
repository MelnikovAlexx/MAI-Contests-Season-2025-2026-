#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector <vector <int> > g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v); g[v].push_back(u);
    }
    vector <int> d(n, inf);
    queue <int> q;
    d[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto &u : g[v]) {
            if (d[u] == inf) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    int vv = 0;
    for (int i = 0; i < n; i++)
        if (d[i] > d[vv]) {
            vv = i;
        }
    q.push(vv);
    for (int i = 0; i < n; i++) {
        d[i] = inf;
    }
    d[vv] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto &u : g[v]) {
            if (d[u] == inf) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }
    int res = vv;
    for (int i = 0; i < n; i++)
        if (d[i] > d[res])
            res = i;
    cout << d[res] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
}