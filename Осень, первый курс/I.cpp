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


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m, d;
    cin >> n >> m >> d;
    set <pair <ll, ll> > s;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        s.insert(make_pair(x, i + 1));
    }
    int cnt = 1;
    vector <int> ans(n, 0);
    while (!s.empty()) {
        auto it = s.begin();
        ll x = it->first;
        ll ind = it->second;
        ans[ind - 1] = cnt;
        while (true) {
            auto it2 = s.upper_bound(make_pair(x + d, (ll)1e9));
            if (it2 == s.end()) break;
            else {
                ans[it2->second - 1] = cnt;
                x = it2->first;
                s.erase(it2);
            }
        }
        cnt++;
        s.erase(it);
    }
    cout << cnt - 1 << "\n";
    for (auto &x: ans) cout << x << " ";
}
