#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 3e5;
int p[MAXN], rg[MAXN];

void make_set(int v) {
    p[v] = v;
    rg[v] = 1;
}

int get(int v) {
    if (p[v] == v) return v;
    return p[v] = get(p[v]);
}

void unite(int a, int b) {
    a = get(a); b = get(b);
    if (a == b) return;
    if (rg[a] > rg[b])
        swap(a, b);
    p[a] = b;
    rg[b] += rg[a];
}

struct Edge{
    int u, v, cost;
};

vector <Edge> edges;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    int a[n];
    for (auto &x: a) cin >> x;
    edges.resize(m);
    for (int i = 0; i < m; i++) 
        cin >> edges[i].u >> edges[i].v >> edges[i].cost;
    for (int i = 0; i < n; i++)
        edges.push_back({0, i + 1, a[i]});
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) {
        return a.cost < b.cost;
    });
    for (int i = 0; i <= n; i++)
        make_set(i);
    for (auto &[u, v, cost] : edges) {
        if (get(u) != get(v)) {
            ans += cost;
            unite(u, v);
        }
    }
    cout << ans << "\n";
    return 0;
}