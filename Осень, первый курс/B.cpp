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
        if (x <= n) {
            for (int i = 0; i < x; i++) cout << "1 ";
            for (int i = x; i < n; i++) cout << "0 ";
            cout << "\n";
            continue;
        }
        set <vector <int> > s2;
        int cur = 0, d = 1, k = 0, period;
        vector <ll> arr(n, 0), arr2(n, 0);
        while (true) {
            vector <int> s1;
            for (int i = 0; i < n; i++)
            {
                if (d == 1) cur++;
                else cur--;

                if (cur == n) d = -1;
                if (cur == 1) d = 1;
                s1.push_back(cur);
            }
            k++;
            if (s2.find(s1) != s2.end()) {
                period = (k - 1) * n;
                break;
            }
            else {
                for (auto &x: s1) arr2[x - 1]++;
                s2.insert(s1);
            }
        }
        if (x >= period) {
            ll p = x / period;
            for (auto &x: arr2) x *= p;
            x %= period;
            cur = 0; d = 1;
            while (x--) {
                if (d == 1) cur++;
                else cur--;

                if (cur == n) d = -1;
                if (cur == 1) d = 1;
                arr2[cur - 1]++;
            }
            for (auto &x: arr2) cout << x << " ";
        }
        else {
            cur = 0; d = 1;
            while (x--) {
                if (d == 1) cur++;
                else cur--;

                if (cur == n) d = -1;
                if (cur == 1) d = 1;
                arr[cur - 1]++;
            }
            for (auto &x: arr) cout << x << " ";
        }
        cout << "\n";
    }
}
