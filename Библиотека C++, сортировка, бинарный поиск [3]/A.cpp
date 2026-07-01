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
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll s = 0;
    for (int i = 1; i <= n; i++) {
        if (i % k != 0) {
            s += a[i - 1];
        }
    }
    cout << s;
}
