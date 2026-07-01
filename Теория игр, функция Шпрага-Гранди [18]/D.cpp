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
    vector <ll> g(n + 1, 0);
    g[1] = 1;
    g[2] = 0;
    for (int i = 3; i <= n; i++) {
        bool fl = false;
        for (int k = 1; k <= n; k++) 
            if (k * k <= i && !g[i - k * k])
                fl = true;
        if (fl) g[i] = 1;
    }
    if (g[n]) cout << 1;
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