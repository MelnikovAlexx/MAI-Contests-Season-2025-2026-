#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
#define db() cout << "\n===================\n";

const ll inf = 1e18;

void solve();
ll calc(vector <vector <ll> > &c, vector <vector <ll> > &dp, int i, ll mask);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--)
        solve();
    return 0;
}

void solve() {
    ll n;
    cin >> n;
    vector <vector <ll> > c(n, vector <ll> (n));
    for (auto &x : c)
        for (auto &y : x) cin >> y;
    vector <vector <ll> > dp((1 << n) + 1, vector <ll> (n, 0));
    for (int i = 0; i < n; i++)
        dp[1 << i][i] = 1;
    for (int mask = 0; mask < 1 << n; mask++) {
        for (int i = 0; i < n; i++) {
            if (!dp[mask][i]) continue;
            for (int j = 0; j < n; j++) {
                if (!(mask & (1 << j))) {
                    if (c[i][j]) dp[mask | (1 << j)][j] += dp[mask][i];
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += dp[(1 << n) - 1][i];
    cout << ans;
}

