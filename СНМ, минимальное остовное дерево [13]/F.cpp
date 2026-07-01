#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int p[MAXN], rg[MAXN];
int minn[MAXN], maxn[MAXN];

vector <int> a;

void make_set(int v) {
    p[v] = v;
    rg[v] = 1;
    minn[v] = a[v]; maxn[v] = a[v];
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
    minn[b] = min(minn[b], minn[a]);
    maxn[b] = max(maxn[b], maxn[a]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    priority_queue <array<int, 5>> q;
    for (int i = 0; i < n; i++)
        make_set(i);
    for (int i = 0; i < n - 1; i++) 
        q.push({-abs(a[i] - a[i + 1]), -a[i], -a[i + 1], get(i), get(i + 1)});
    while (q.size() != 0) {
        array<int,5> t = q.top();
        q.pop();
        int dst = -t[0], left = -t[1], right = -t[2], u = get(t[3]), v = get(t[4]);
        cout << minn[u] << " " << maxn[u] << " " << minn[v] << " " << maxn[v] << "\n";
        unite(u, v);
    }
}