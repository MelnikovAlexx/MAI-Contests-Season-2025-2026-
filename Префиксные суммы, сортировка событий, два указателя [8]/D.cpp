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
    ll n, cur = 0;
    cin >> n;
    vector <ll> a(n, 0);
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        cur += x;
        a[i] = cur;
    }
    vector <ll> maxx(n + 1, -1e18);
    map <ll, ll> dd;
    for (int i = n - 1; i > -1; i--)
    {
        if (i == n - 1) {
            maxx[i] = a[i];
            dd[i] = n - 1;
        }
        else {
            maxx[i] = max(maxx[i + 1], a[i]);
            if (maxx[i + 1] > a[i]) dd[i] = dd[i + 1];
            else dd[i] = i;
        }
    }
    ll mx = -1e18, t1 = -1, t2 = -1;
    if (0 < maxx[0]) {
        mx = maxx[0];
        t1 = 1;
        t2 = dd[0] + 2;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] < maxx[i + 1] && maxx[i + 1] - a[i] > mx) {
            mx = maxx[i + 1] - a[i];
            t1 = i + 2;
            t2 = dd[i + 1] + 2;
        }
    }
    cout << t1 << " " << t2;
}
