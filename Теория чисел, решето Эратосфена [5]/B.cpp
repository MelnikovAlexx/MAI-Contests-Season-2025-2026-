#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <numeric>
#include <set>
#include <map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define vll vector <ll>
#define vi vector<int>
#define pii pair <int, int>
#define pll pair <ll, ll>


template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll P = 1e3;
ll primes[P + 1];

bool is_prime(ll n) {
    if (n == 1) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void linear_sieve() {
    vector<ll> p;

    for (ll k = 2; k <= P; k++) {
        if (primes[k] == 0) {
            primes[k] = k;
            p.push_back(k);
        }
        for (int j = 0; j < (int)p.size() && p[j] <= primes[k] && k * p[j] <= P; ++j)
            primes[k * p[j]] = p[j];
    }
}

vector <char> sieve(ll n) {
    vector<char> prime (n + 1, true);
    prime[0] = prime[1] = false;
    for (ll i = 2; i <= n; ++i)
        if (prime[i])
            if (i * i <= n)
                for (ll j = i * i; j <= n; j += i)
                    prime[j] = false;
    return prime;
}

ll gcd(ll a, ll b, ll &x, ll &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	ll x1, y1;
	ll d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, l = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        l = lcm(l, x);
    }
    cout << l;
}
