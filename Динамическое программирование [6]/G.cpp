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
    ll n, k;
    map <ll, set <ll> > can;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int icpy = i;
        set <int> set1;
        while (icpy != 0) {
            set1.insert(icpy % 10);
            icpy /= 10;
        }
        for (int j = 1; j <= k; j++) {
            int jc = j;
            bool fl = true;
            while (jc != 0) {
                if (set1.find(jc % 10) != set1.end()) {
                    fl = false;
                    break;
                }
                jc /= 10;
            }
            if (fl) can[i].insert(j);
        }
    }
    vector <vector <ll> > dp(n + 1, vector <ll> (k + 1, 0));
    if (n == 1) {
        cout << k;
        return 0;
    }
    for (int j = 1; j <= k; j++)
        dp[1][j] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (auto &x: can[j])
            {
                dp[i][j] += dp[i - 1][x];
                dp[i][j] %= mod;
            }
        }
    }
    ll ans = 0;
    for (int j = 1; j <= k; j++)
    {
        ans += dp[n][j];
        ans %= mod;
    }
    cout << ans;
}
