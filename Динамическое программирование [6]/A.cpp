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
    ll n, k, d, l;
    cin >> n >> l >> k;
    vector <ll> dp(n + 1, 0);
    dp[0] = 1;
    vector <ll> p(k);
    map <ll, ll> d2;
    for (auto &x: p) {
        cin >> x;
        d2[x] = -1;
    }
    vector <ll> pref(n + 2, 0);
    pref[1] = 1;
    for (int i = 1; i <= n; i++) {
        if (d2[i] == -1) {
            pref[i + 1] = pref[i] + dp[i];
            continue;
        }
        dp[i] = (pref[i] - pref[max((ll)0, i - l)]) % mod;
        pref[i + 1] = pref[i] + dp[i];
    }
    cout << dp[n];
}
