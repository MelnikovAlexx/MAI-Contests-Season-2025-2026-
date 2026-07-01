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

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    set <int> sq;
    for (int i = 1; i <= 10001; i++)
        sq.insert(i * i);
    for (int i = 1; i <= n; i++)
        make_set(i);
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--) {
            if ((i * i + j * j) % k == 0) {
                int num = (i * i + j * j) / k;
                if (sq.find(num) != sq.end()) {
                    if (get(i) == get(j)) {
                        cout << i << "\n";
                        return 0;
                    }
                    unite(i, j);
                }
            }
        }
    }
    cout << -1;
}   