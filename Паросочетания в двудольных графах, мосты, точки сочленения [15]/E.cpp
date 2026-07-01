#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e5;
vector<int> g[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];
int parent[MAXN], rg[MAXN];
int cnt = 0;

vector <pair <int, int> > bridges;
 
void make_set(int v) {
    parent[v] = v;
    rg[v] = 1;
}

int get(int v) {
    if (parent[v] == v) return v;
    return parent[v] = get(parent[v]);
}

void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    if (rg[a] > rg[b])
        swap(a, b);
    parent[a] = b;
    rg[b] += rg[a];
}

void dfs (int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p)  continue;
		if (used[to])
			fup[v] = min(fup[v], tin[to]);
		else {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > tin[v])
				bridges.push_back({v, to});
            else unite(v, to);
		}
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        make_set(i);
	for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
	timer = 0;
	dfs(0);
    vector <vector <int> > bg(MAXN);
    int rnd_v;
    for (auto &[a, b] : bridges) {
        int u = get(a), v = get(b);
        rnd_v = u;
        bg[u].push_back(v);
        bg[v].push_back(u);
    }
    queue <int> q;
    vector <int> d1(MAXN, 1e9), d2(MAXN, 1e9);
    q.push(rnd_v);
    d1[rnd_v] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto &u: bg[v]) {
            if (d1[u] == 1e9) {
                d1[u] = d1[v] + 1;
                q.push(u);
            }
        }
    }
    int mx = -1, mx_v = rnd_v;
    for (int i = 0; i < MAXN; i++) {
        if (d1[i] != 1e9 && d1[i] > mx) {
            mx = d1[i];
            mx_v = i;
        }
    }
    q.push(mx_v);
    d2[mx_v] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto &u: bg[v]) {
            if (d2[u] == 1e9) {
                d2[u] = d2[v] + 1;
                q.push(u);
            }
        }
    }
    int ans = -1;
    for (auto &x : d2)
        if (x != 1e9 && x > ans) ans = x;
    cout << ans;
}