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
    ll t, n, x;
    cin >> t;
    while (t--) {
        cin >> x >> n;
        if (n == 1) {
            cout << x << "\n";
            continue;
        }
        if (x < n) {
            cout << "-1\n";
            continue;
        }
        vector <ll> ans(n, x / n);
        int cur = 0;
        x %= n;
        while (x--) {
            ans[cur]++;
            cur++; cur %= n;
        }
        sort(ans.begin(), ans.end());
        for (auto &x: ans) cout << x << " ";
        cout << "\n";
    }
}
