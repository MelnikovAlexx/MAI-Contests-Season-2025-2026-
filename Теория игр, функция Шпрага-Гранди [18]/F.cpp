#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
#define db() cout << "\n===================\n";

const ll inf = 1e18;


void solve() {
    ll n, m;
    cin >> n >> m;
    if (n % 2 == 1 && m % 2 == 1) cout << 2;
    else if (n % 2 == 0 && m % 2 == 0) cout << 1;
    else cout << 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--)
        solve();
    return 0;
}