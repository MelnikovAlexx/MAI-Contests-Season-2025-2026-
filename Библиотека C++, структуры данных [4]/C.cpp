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
    multiset <ll> s;
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        s.insert(x);
    }
    while (s.size() != 1) {
        auto it = s.begin();
        auto it2 = s.begin();
        it2++;
        cout << *it << " " << *it2 << "\n";
        s.insert(*it + *it2);
        s.erase(it);
        s.erase(it2);
    }
}
