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


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, q;
    cin >> n >> q;
    vector <ll> d(n + 2, 0);
    while (q--) {
        ll l, r, x;
        cin >> l >> r >> x;
        d[l] += x;
        d[r + 1] -= x;
    }
    vector <ll> pref(n + 2, 0);
    for (int i = 1; i <= n + 1; i++)
        pref[i] = pref[i - 1] + d[i];
    for (int i = 1; i <= n; i++) cout << pref[i] << " ";
}
