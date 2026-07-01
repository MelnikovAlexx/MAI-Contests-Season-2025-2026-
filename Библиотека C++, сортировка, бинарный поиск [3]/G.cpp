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
        ll n;
        cin >> n;
        vector <pll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i + 1;
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int j = i + 1;
            while (a[i].first * a[j].first <= 2 * n - 1) {
                if (a[i].second + a[j].second == a[i].first * a[j].first)
                    ans++;
                j++;
                if (j == n)
                    break;
            }
        }
        cout << ans << "\n";

    }
}
