#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > g;
vector <long long> dp;
long long ans = 0;

void dfs(int v, int n) {
    dp[v] = 1;
    for (auto &u : g[v]) {
        if (dp[u] == 0) {
            dfs(u, n);
            dp[v] += dp[u];
            ans += (n - dp[u]) * dp[u];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    g.resize(n);
    dp.resize(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, n);
    cout << ans;
}