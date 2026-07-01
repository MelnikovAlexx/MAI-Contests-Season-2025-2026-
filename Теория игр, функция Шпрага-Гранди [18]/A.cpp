#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
#define db() cout << "\n===================\n";

const ll inf = 1e18;


void solve() {
    ll n, a, b, ans = 0;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        ll x;
        ans = (ans ^ (a % (b + 1)));
    }
    if (!ans) cout << 2;
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