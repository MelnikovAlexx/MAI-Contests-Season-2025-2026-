#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;

int parent[MAXN], rg[MAXN];

void make_set(int v) {
    parent[v] = v;
    rg[v] = 1;
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
        return;
    }
	if (rg[a] > rg[b])
        swap(a, b);
    parent[a] = b;
    rg[b] += rg[a];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        make_set(i + 1);
    vector <pair <int, int> > arr;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        arr.push_back({u, v});
    }
    reverse(arr.begin(), arr.end());
    vector <int> ans = {n};
    int cnt = n;
    for (auto &[u, v] : arr) {
        if (get(u) != get(v)) {
            unite(u, v);
            cnt--;
        }
        ans.push_back(cnt);
    }
    ans.pop_back();
    reverse(ans.begin(), ans.end());
    for (auto &x: ans)
        cout << x << "\n";
}