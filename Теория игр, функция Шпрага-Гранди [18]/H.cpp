#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
#define db() cout << "\n===================\n";

const ll inf = 1e18;


void solve() {
    ll n;
    cin >> n;
    ll i = 2;
    unordered_map <ll, int> d;
    while (i * i <= n) {
        if (n % i == 0) {
            n /= i;
            d[i]++;
        }
        else i++;
    }
    if (n != 1) d[n]++;
    ll ans = 0;
    for (auto &x : d)
        ans ^= x.second;
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