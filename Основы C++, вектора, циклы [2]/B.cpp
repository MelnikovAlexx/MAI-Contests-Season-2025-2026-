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
    vll fib = {0, 1};
    for (int i = 0; i < 90; i++) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
       // cout << fib[fib.size() - 1] << "\n";
    }
    for (int i = 0; i < fib.size(); i++) {
        if (fib[i] == n) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}

