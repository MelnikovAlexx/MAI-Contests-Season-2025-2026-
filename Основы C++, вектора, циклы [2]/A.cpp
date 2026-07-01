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
    int n; cin >> n;
    vi a(n); for (auto &x: a) cin >> x;
    int l, r;
    cin >> l >> r;
    while (l + r != 0) {
        reverse(a.begin() + l - 1, a.begin() + r);
       // for (auto &x: a) cout << x << " ";
       // cout << "\n";
        cin >> l >> r;
    }
    for (auto &x: a) cout << x << " ";
}

