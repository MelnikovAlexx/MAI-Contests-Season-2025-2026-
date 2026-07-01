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
        int n; cin >> n;
        int a, b, c, d, e;
        e = n / 5000;
        n %= 5000;
        d = n / 1000;
        n %= 1000;
        c = n / 500;
        n %= 500;
        b = n / 200;
        n %= 200;
        a = n / 100;
        n %= 100;
        cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
    }
}

