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

ll f(ll x) {
    ll r = 0;
    while (x) {
        r += x % 10;
        x /= 10;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector <int> a(1e6 + 1, 0);
    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        a[x]++;
    }
    while (k) {
        bool fl = false;
        for (int i = 1000000; i >= 0; i--) {
            if (a[i]) {
                fl = true;
                if (a[i] >= k) {
                    cout << f(i);
                    return 0;
                }
                else {
                    ll xn = i - f(i);
                    k -= a[i];
                    a[xn] += a[i];
                    a[i] = 0;

                }
            }
        }
        if (!fl)
        {
            cout << 0;
            return 0;
        }
    }
}
