#include <bits/stdc++.h>
using namespace std;


vector <char> letters;
vector <bool> used;
vector <vector <int> > g;

map <int, unsigned > dm;
map <unsigned, vector <int> > d;

void dfs(int v) {
    used[v] = 1;
    dm[v] |= (1 << int(letters[v] - 'a'));
    for (auto &u : g[v]) {
        if (!used[u]) {
            dfs(u);
            dm[v] |= dm[u];
        }
    }
    d[dm[v]].push_back(v);
}

int main() {
    int n;
    cin >> n;
    letters.resize(n);
    g.resize(n);
    used.resize(n, 0);
    for (auto &x : letters) cin >> x;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    for (auto &x : d) {
        if (x.second.size() >= 2) {
            cout << x.second[0] + 1 << " " << x.second[1] + 1 << "\n";
            return 0;
        }
    }
    cout << "-1 -1";
}