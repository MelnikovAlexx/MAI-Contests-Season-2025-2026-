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

vector <vector <int> > g;
vector <int> used;
vector <int> path;
vector <int> pred;
vector <int> dp;
vector <int> topsort;
int n, m, max_p = 0, cur = 0, max_v = 0;

void dfs1(int);
void dfs(int, int, int);

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    dp.resize(n, 1);
    pred.resize(n, -1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }   
    for (int i = 0; i < n; i++)
        if (!used[i]) dfs1(i);
    used.clear(); used.resize(n, 0);
    for (int i = topsort.size() - 1; i > 0; i--) {
        int v = topsort[i];
        for (auto &u : g[v]) {
            if (dp[v] + 1 > dp[u]) {
                dp[u] = dp[v] + 1;
                pred[u] = v;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dp[i] > max_p) {
            max_p = dp[i];
            max_v = i;
        }
    }
    while (max_v != -1) {
        path.push_back(max_v);
        max_v = pred[max_v];
    }
    reverse(path.begin(), path.end());
    cout << max_p << "\n";
    for (auto &x : path)
        cout << x + 1 << " ";
}

void dfs1(int v) {
    used[v] = 1;
    for (auto &u : g[v])
        if (!used[u])
            dfs1(u);
    topsort.push_back(v);
}

void dfs(int v, int depth, int prev) {
    used[v] = 1;
    if (depth > dp[v])
    {
        dp[v] = depth;
        pred[v] = prev;
    } 
    for (auto &u : g[v]) {
        if (!used[u])  
            dfs(u, depth + 1, v);
    }
}

