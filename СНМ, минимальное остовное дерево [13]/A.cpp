#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;


int parent[MAXN], rg[MAXN];
long long sum[MAXN], minn[MAXN], maxn[MAXN];

void make_set(int v) {
    parent[v] = v;
    rg[v] = 1;
    sum[v] = v;
    minn[v] = v;
    maxn[v] = v;
}

int get(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = get(parent[v]);
}
 
void unite(int a, int b) {
	a = get(a);
	b = get(b);
    if (a == b) {
        cout << sum[b] << " " << minn[b] << " " << maxn[b] << "\n";
        return;
    }
	if (rg[a] > rg[b])
        swap(a, b);
    parent[a] = b;
    rg[b] += rg[a];
    sum[b] += sum[a];
    minn[b] = min(minn[b], minn[a]);
    maxn[b] = max(maxn[b], maxn[a]);
    cout << sum[b] << " " << minn[b] << " " << maxn[b] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        make_set(i + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        unite(u, v);
    }
}