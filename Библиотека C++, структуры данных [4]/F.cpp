#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
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
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    a.push_back(1e10);
    ll m = n / 2, l = 1, ans = a[m];
    for (int i = m + 1; i <= n; i++) {
        ll d = a[i] - a[i - 1];
        if (d * l <= k) {
            k -= d * l;
            l++;
            ans = a[i];
        }
        else {
            ans += (k / l);
            break;
        }
    }
    cout << ans;
}
