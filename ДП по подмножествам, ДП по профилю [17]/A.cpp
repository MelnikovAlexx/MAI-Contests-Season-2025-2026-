#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
#define db() cout << "\n===================\n";

void solve();

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--)
        solve();
    return 0;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = -1e18;
    for (int i = 0; i < (1 << n); i++) {
        if (__builtin_popcount(i) == k) {
            ll cur = -1;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    if (cur == -1) cur = a[j];
                    else cur = cur ^ a[j];
                }
            }
            ans = max(ans, cur);
        }
    }
    cout << ans << "\n";
}
