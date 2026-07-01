#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define ll long long

bool is_prime(ll n) {
    if (n == 1) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

const int P = 5e7;
int primes[P + 1];


void linear_sieve() {
    vector<int> p;

    for (int k = 2; k <= P; k++) {
        if (primes[k] == 0) {
            primes[k] = k;
            p.push_back(k);
        }
        for (int j = 0; j < (int)p.size() && p[j] <= primes[k] && k * p[j] <= P; ++j)
            primes[k * p[j]] = p[j];
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    linear_sieve();
    cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 0) {
            cout << 0;
            continue;
        }
        if (primes[n] == n) cout << "Prime\n";
        else {
            int cnt = 0;
            set <int> divs;
            while (n != 1) {
                divs.insert(primes[n]);
                n /= primes[n];
            }
            cout << divs.size() << "\n";
        }
    }
}
