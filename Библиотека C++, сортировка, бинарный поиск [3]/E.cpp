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
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vll a(n);
        for (auto &x: a) cin >> x;
        sort(a.begin(), a.end());
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int l = i, r = n, mid;
            while (r - l > 1) {
                mid = (r + l) / 2;
                if (a[i] * a[mid] <= m)
                    l = mid;
                else r = mid;
            }
            if (a[i] * a[l] <= m && i != l) {
                ans += (l - i);
            }
        }
        cout << ans << "\n";
    }
}
