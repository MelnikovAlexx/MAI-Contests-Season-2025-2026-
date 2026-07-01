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
deque <int> ans;
vector <int> used;

int s, f;

void dfs(int);

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
            c++;
        }
    }
    cout << c;
}

void dfs(int v) {
    used[v] = 1;
    for (auto &u : g[v]) 
        if (!used[u])
            dfs(u);
}
