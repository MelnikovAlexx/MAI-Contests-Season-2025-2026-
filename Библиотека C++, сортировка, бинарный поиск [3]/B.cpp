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
    vector <pll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = (i + 1);
    }
    sort(a.begin(), a.end());
    bool fl = true;
    vi ans;
    for (int i = 0; i < n; i++) {
        if (k > a[i].first) {
            ans.push_back(a[i].second);
            k += a[i].first;
        }
        else fl = false;
    }
    if (!fl) cout << "NO";
    else {
        cout << "YES\n";
        for (auto &x: ans) cout << x << " ";
    }
}
