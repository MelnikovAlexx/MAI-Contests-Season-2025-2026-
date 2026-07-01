#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e9, mod = inf + 7;

struct P{
    int x, y;
};

long double dst(P &a, P &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    P a[n];
    for (auto &x: a)
        cin >> x.x >> x.y;
    vector <vector <int> > g(n);
    for (int i = 0; i < n - 1; i++) {
        g[i].push_back(i + 1);
        g[i + 1].push_back(i);
    }
    g[0].push_back(n - 1);
    g[n - 1].push_back(0);
    long double minn = 1e18;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            g[i].push_back(j);
            g[j].push_back(i);
            long double ans = 0;
            for (int s = 0; s < n; s++) {
                priority_queue <pair <int, long double> > q;
                vector <long double> ds(n, 1e18);
                ds[s] = 0;
                q.push({s, 0});
                while (!q.empty()) {
                    int v = q.top().first;
                    q.pop();
                    for (auto &u : g[v]) {
                        if (ds[u] > ds[v] + dst(a[u], a[v])) {
                            ds[u] = ds[v] + dst(a[u], a[v]);
                            q.push({u, -ds[u]});
                        }
                    }
                }
                for (auto &x : ds) ans += x;
            }
            g[i].pop_back();
            g[j].pop_back();
            minn = min(minn, ans);
        }
    }
    cout << fixed << setprecision(8) << minn;
}

