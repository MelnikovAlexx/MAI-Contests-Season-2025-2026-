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
    ll n;
    cin >> n;
    vector <vll> a(n, vll (n));
    for (auto &x: a)
        for (auto &y: x) cin >> y;
    vll arr;
    for (auto &x: a) {
        for (auto &y: x) arr.push_back(y);
    }
    sort(arr.begin(), arr.end());
    ll c = arr[1] - arr[0], d;
    set <ll> set1, set2;
    ll k = arr[0];
    for (int i = 0; i < n; i++) {
        set1.insert(k);
        k += c;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (set1.find(arr[i]) == set1.end()) {
            d = arr[i] - arr[0];
            cout << c << " " << d;
            return 0;
        }
        else {
            set1.erase(set1.find(arr[i]));
        }
    }

}
