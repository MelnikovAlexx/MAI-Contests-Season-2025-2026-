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
    ll x, y, s = 0;
    cin >> x >> y;
    int t; cin >> t;
    vector <pll> a(t);
    for (int i = 0; i < t; i++) {
        cin >> a[i].first >> a[i].second;
        s += a[i].second;
    }
    s /= t;
    ll mn = 1e18, ans = 0;
    map <int, pii> d;
    for (auto &x: a) {
        d[x.first] = {1e9, -1e9};
    }
    for (auto &x: a) {
        pii pp = d[x.first];
        if (x.second > pp.second) pp.second = x.second;
        if (x.second < pp.first) pp.first = x.second;
        d[x.first] = pp;
       // cout << x.first << " " << pp.first << " " << pp.second << "\n";
    }
    for (int i = max((ll)0, s - 100); i <= min(y, s + 100); i++) {
        ll dst = x - 1;
        for (auto &x: d) {
            if (x.second.first < i) dst += 2 * abs(x.second.first - i);
            if (x.second.second > i) dst += 2 * abs(x.second.second - i);
        }
        //cout << dst << " " << i << "\n";
        if (dst < mn) {
            mn = dst;
        }
    }
    cout << mn;

}
