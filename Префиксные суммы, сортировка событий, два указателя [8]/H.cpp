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

const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector <ll> a(n);
    for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    a.push_back(1e18);
    ll ans = 0;
    for (int i = 0; i < n - 2; i++) {
        auto it = upper_bound(a.begin(), a.end(), a[i] + k);
        it--;
        ll d = (it - a.begin()) - i - 1;
        ans += d * (d + 1) / 2;
    }
    cout << ans;
}
