#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <deque>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

const int inf = 1e9;

vector <vector<int> > g;
deque <int> path;
vector <int> used;

int s, f;
void dfs(int);

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v;
    cin >> n >> m >> s >> f;
    s--; f--;
    g.resize(n);
    used.resize(n, 0);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(s);
    cout << -1;
}

void dfs(int v) {
    if (v == f) {
        for (auto &x: path)
            cout << x + 1 << " ";
        cout << f + 1;
        exit(0);
    }
    used[v] = 1;
    path.push_back(v);
    for (auto &u : g[v]) {
        if (!used[u])
            dfs(u);
    }
    path.pop_back();
}

