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
vector <int> d;
vector <int> pred;

int s, f;

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v;
    cin >> n >> m >> s >> f;
    s--; f--;
    g.resize(n);
    d.resize(n, inf);
    pred.resize(n, -1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
        sort(g[i].begin(), g[i].end());
    queue <int> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto &u : g[v]) {
            if (d[u] == inf) {
                q.push(u);
                pred[u] = v;
                d[u] = d[v] + 1;
            }
        }
    }
    if (d[f] == inf) {
        cout << -1;
        return 0;
    }
    while (f != -1) {
        path.push_back(f);
        f = pred[f];
    }
    reverse(path.begin(), path.end());
    for (auto &x: path)
        cout << x + 1 << " ";
}   
