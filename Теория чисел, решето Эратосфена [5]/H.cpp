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
    ll t;
    cin >> t;
    while (t--) {
        ll x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x2 = abs(x2 - x1);
        y2 = abs(y2 - y1);
        cout << __gcd(x2, y2) + 1 << "\n";
    }
}
