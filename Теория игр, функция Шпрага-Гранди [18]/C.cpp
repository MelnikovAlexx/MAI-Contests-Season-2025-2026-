#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
#define db() cout << "\n===================\n";

const ll inf = 1e18;


void solve() {
    int n;
    cin >> n;
    vector <ll> g(n + 1);
    g[0] = g[1] = g[2] = 0;
    for (int i = 3; i <= n; i++) {
        g[i] = 0;
        set <int> s;
        for (int k = 1; k < i; k++)
            if (k != i - k)
                s.insert(g[k] ^ g[i - k]);
        for (int j = 0; j < n; j++)
            if (s.count(j) == 0) {
                g[i] = j;
                break;
            }
    }
    if (g[n] != 0) cout << 1;
    else cout << 2;
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--)
        solve();
    return 0;
}