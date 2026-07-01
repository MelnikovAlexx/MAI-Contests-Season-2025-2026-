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
    ll p, q;
    cin >> p >> q;
    if (p % q != 0 || p == q)
        cout << -1;
    else {
        ll k = p / q, c = 0;
        while (true) {
            k--;
            c++;
            if (q * k + q * c == p) {
                cout << q * k << " " << q * c;
                return 0;
            }
        }
    }
}
