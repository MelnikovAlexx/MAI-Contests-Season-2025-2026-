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
    vi a(n);
    for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] != 1) {
            cout << "Scammed";
            return 0;
        }
    }
    cout << "Deck looks good";
}
