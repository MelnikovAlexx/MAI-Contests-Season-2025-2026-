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


ll f(ll x) {
    ll r = 0;
    while (x) {
        r += x % 10;
        x /= 10;
    }
    return r;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    map <ll, ll> d;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d[a[i]]++;
    }
    ll maxn = *max_element(a.begin(), a.end());
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (k < a[i]) {
            ll x = k;
            while (x <= maxn) {
                ans += d[x];
                x += a[i];
            }
        }
    }
    cout << ans;
}
