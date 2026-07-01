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
    ll n, k;
    cin >> n >> k;
    if (k == 1) {
        while (n != 1) {
            cout << "0 ";
            n -= (n / 2);
        }
        return 0;
    }
    while (k != 1) {
        ll ch, nc;
        ch = n / 2;
        nc = n / 2;
        if (n % 2 == 1)
            nc++;
        if (k % 2 == 1) {
            cout << "0 ";
            k = k - (k / 2);
            n -= ch;
        }
        else {
            cout << "1 ";
            k = k - (k / 2);
            n -= nc;
        }
    }
    while (n != 1) {
        cout << "0 ";
        n -= n / 2;
    }
}
