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
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector <ll> a(n);
        for (auto &x: a) cin >> x;
        if (n == 1)
        {
            cout << "1\n";
            continue;
        }
        set <ll> s;
        ll ans = 1, l = 0, r = 1;
        s.insert(a[l]);
        bool fl = true;
        while (r < n) {
            while (s.find(a[r]) == s.end()) {
                s.insert(a[r]);
                ans = max(r - l + 1, ans);
                r++;
                if (r == n) {
                    fl = false;
                    break;
                }
            }
            if (!fl) break;
            while (a[r] != a[l]) {
                s.erase(s.find(a[l]));
                l++;
            }
            s.erase(s.find(a[l]));
            l++;
        }
        cout << ans << "\n";
    }
}
