#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
using namespace std;

#define ll long long
#define vll vector <ll>
#define vi vector<int>
#define pii pair <int, int>
#define pll pair <ll, ll>

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vll a(n);
    for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    int q; cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        if (l > r) swap(l, r);
        auto x = upper_bound(a.begin(), a.end(), l);
        auto y = upper_bound(a.begin(), a.end(), r);
        y--;
        if (x == a.end() || *x > r) cout << 0 << "\n";
        else if (y == a.end() || *y < l) cout << 0 << "\n";
        else cout << max((ll)0, (ll)(y - x + 1)) << "\n";
    }
}
