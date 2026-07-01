#include <bits/stdc++.h>
using namespace std;

const int MAXN = 7e6;

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
    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        int cnt = 0;
        unordered_set <int> used;
        while (q--) {
            int x, y;
            cin >> x >> y;
            make_set(x * m + y);
            used.insert(x * m + y);
            cnt++;
            if (x - 1 > 0 && used.find((x - 1) * m + y) != used.end()) {
                int a = get(x * m + y), b = get((x - 1) * m + y);
                if (a != b) {
                    cnt--;
                    unite(a, b);
                }
            }
            if (x + 1 <= n && used.find((x + 1) * m + y) != used.end()) {
                int a = get(x * m + y), b = get((x + 1) * m + y);
                if (a != b) {
                    cnt--;
                    unite(a, b);
                }
            }
            if (y - 1 > 0 && used.find(x * m + y - 1) != used.end()) {
                int a = get(x * m + y), b = get(x * m + y - 1);
                if (a != b) {
                    cnt--;
                    unite(a, b);
                }
            }
            if (y + 1 <= m && used.find(x * m + y + 1) != used.end()) {
                int a = get(x * m + y), b = get(x * m + y + 1);
                if (a != b) {
                    cnt--;
                    unite(a, b);
                }
            }
            cout << cnt << "\n";
        }
    }
}