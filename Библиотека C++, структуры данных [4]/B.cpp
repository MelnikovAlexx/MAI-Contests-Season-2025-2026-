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
    ll n, a0, k = 1, mx1 = -1e9, mx2 = -1e9;
    cin >> n >> a0;
    set <ll> s;
    for (int i = 1; i <= n; i++) {
        k *= 5;
        k %= (ll)(1e9 + 7);
        ll x = (a0 * k) % (ll)(1e9 + 7);
        if (x > mx1) {
            mx2 = mx1;
            mx1 = x;
        }
        else if (x > mx2) mx2 = x;
    }
    cout << mx2 << " " << mx1;
}
