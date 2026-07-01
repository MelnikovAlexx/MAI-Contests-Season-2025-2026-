#include <bits/stdc++.h>
using namespace std;

//#define int long long
const int inf = 1e9, mod = inf + 7;


signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;
    char f[n][m];
    for (auto &x : f)
        for (auto &y : x) cin >> y;

    vector <vector <array<int, 3> > > g(n * m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] != '#') {
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue;
                        if (i + di >= 0 && j + dj >= 0 && i + di < n && j + dj < m) {
                            if (f[i + di][j + dj] != '#') {
                                if (f[i + di][j + dj] != f[i][j])
                                    g[i * m + j].push_back({(i + di) * m + j + dj, 1, 1});
                                else
                                    g[i * m + j].push_back({(i + di) * m + j + dj, 0, 1});
                            }
                        }
                    }
                }
            }
        }
    }
    int s = x1 * m + y1, fn = x2 * m + y2;
    vector <int> d(n * m, inf);
    vector <int> d2(n * m, inf);
    d2[s] = 1;
    d[s] = 0;
    priority_queue <array<int, 3>> q;
    q.push({0, -1, s});
    vector <int> p(n * m, -1);
    while (!q.empty()) {
        int v = (q.top())[2];
        q.pop();

        for (auto &[u, c1, c2] : g[v]) {
            if (d[v] + c1 < d[u]) {
                d[u] = d[v] + c1;
                d2[u] = d2[v] + c2;
                q.push({-d[u], -d2[u], u});
            }
            else if (d[v] + c1 == d[u] && d2[u] > d2[v] + 1) {
                d2[u] = d2[v] + 1;
                q.push({-d[u], -d2[u], u});
            }
        }
    }
    if (d[fn] == inf) cout << "0 0";
    else {
        cout << d2[fn] << " " << d[fn];
    } 
}
