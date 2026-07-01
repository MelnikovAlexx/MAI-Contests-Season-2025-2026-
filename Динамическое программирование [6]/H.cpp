#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <numeric>
#include <set>
#include <map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define vll vector <ll>
#define vi vector<int>
#define pii pair <int, int>
#define pll pair <ll, ll>


template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


vector <ll> LCS(vector <ll> &a) {
    int n = a.size();
    vector <ll> p(n + 1, -1);
    vector <ll> prev(n + 1, -1);
    vector <ll> d(n + 1, 1e18);
    d[0] = -1e18;
    for (int i = 0; i < n; i++) {
        int j = int(upper_bound(d.begin(), d.end(), a[i]) - d.begin());
        if (d[j - 1] < a[i] && a[i] < d[j]) {
            d[j] = a[i];
            p[j] = i;
            prev[i] = p[j - 1];
        }
    }
    vector <ll> path;
    ll i = n;
    while (d[i] == 1e18)
        i--;
    ll j = p[i];
    while (j >= 0) {
        path.push_back(a[j]);
        j = prev[j];
    }
    if (path.size() == 1)
        cout << a[1];
    else
        for (i = path.size() - 1; i > -1; i--)
            cout << path[i] << " ";
    cout << "\n";
    return d;
}


const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector <vector <ll> > a(n, vector <ll> (m)), dp(n, vector <ll> (m));
        for (auto &x: a)
            for (auto &y: x) cin >> y;
        ll g = __gcd(a[0][0], a[n - 1][m - 1]), ans = 1;
        for (ll div = 1; div * div <= g; div++) {
            if (g % div == 0) {
                // div
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++) dp[i][j] = 0;
                dp[0][0] = 1;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (a[i][j] % div == 0) {
                            if (i - 1 >= 0)
                                dp[i][j] = dp[i - 1][j];
                            if (!dp[i][j] && j - 1 >= 0)
                                dp[i][j] = dp[i][j - 1];
                        }
                    }
                }
                if (dp[n - 1][m - 1])
                    ans = max(ans, div);
                // g / div
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++) dp[i][j] = 0;
                dp[0][0] = 1;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (a[i][j] % (g / div) == 0) {
                            if (i - 1 >= 0)
                                dp[i][j] = dp[i - 1][j];
                            if (!dp[i][j] && j - 1 >= 0)
                                dp[i][j] = dp[i][j - 1];
                        }
                    }
                }
                if (dp[n - 1][m - 1])
                    ans = max(ans, g / div);
            }
        }
        cout << ans << "\n";
    }
}
