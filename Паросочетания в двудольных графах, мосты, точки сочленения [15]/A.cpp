#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > g, pg;
vector <int> used;
vector <int> color;
vector <int> mt;

int cnt = 0;
bool fl = true;

void dfs(int v, int c) {
    color[v] = c;
    for (auto &u : g[v]) {
        if (!color[u])
            dfs(u, 3 - c);
        else if (color[u] == color[v])
            fl = false;
    }
}

bool kuhn(int v) {
    if (used[v]) return false;
    used[v] = true;
    for (auto &u : pg[v]) {
        if (mt[u] == -1 || kuhn(mt[u])) {
            mt[u] = v;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
    cin >> n >> m;
    g.resize(n);
    pg.resize(n);
    used.resize(n, 0);
    color.resize(n, 0);
    mt.resize(n, -1);
    multiset <pair <int, int> > edges;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        edges.insert({u - 1, v - 1});
    }
    for (auto &[u, v]: edges) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
        if (!color[i])
            dfs(i, 1);
    if (!fl) {
        cout << -1;
        return 0;
    }

    for (auto [a, b] : edges) {
        if (color[a] == 1 && color[b] == 2)
            pg[a].push_back(b);
        if (color[a] == 2 && color[b] == 1)
            pg[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        for (auto &x : used) x = 0;
        if (kuhn(i))
            cnt++;
    }
    cout << cnt << "\n";
    for (int i = 0; i < n; i++) 
        if (mt[i] != -1) cout << i + 1 << " " << mt[i] + 1 << "\n";
}