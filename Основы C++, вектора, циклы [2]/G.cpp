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
    ll n, x, s = 0;
    cin >> n >> x;
    vector <pll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        s += a[i].first;
    }
    s /= n;
    ll mn = 1e18, ans = 0;
    for (int i = max((ll)0, s - 10); i <= min(x, s + 10); i++) {
        ll dst = 0;
        for (auto &x: a) {
            dst += (x.first - i) * (x.first - i) + (x.second * x.second);
        }
        if (dst < mn) {
            mn = dst;
            ans = i;
        }
    }
    cout << mn << " " << ans;

}

