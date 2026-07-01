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


ll C(ll n, ll k) {
    ll c = 1;
    for (ll i = 1; i <= min(k, n - k); i++)
        c = c * (n - i + 1) / i;
    return c;
}

vector <vector <ll> > C_2(ll n, ll k) {
    vector <vector <ll> > c(k, vector <ll> (n, 0));
    c[0][0] = 1;
    for (ll j = 1; j <= n; j++)
        for (ll i = 0; i <= j; i++)
            c[i][j] = c[i - 1][j - 1] + c[i][j - 1];
    return c;
}


const ll mod = 1e9 + 7;

ll inv(ll a, ll m) {
    a = abs(a);
    if (a == 1)
        return 1;
    return (1 - 1ll * inv(m % a, a) * m) / a + m;
}

ll f(ll q, ll n) {
    ll r = 1;
    for (int i = 0; i < n; i++) {
        r *= q;
        r %= mod;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector <ll> fact(n + m + 1, 0);
    fact[0] = 1;
    for (int i = 1; i < fact.size(); i++)
        fact[i] = (fact[i - 1] * i) % mod;
    cout << (((fact[n + m] * inv(fact[n], mod)) % mod) * inv(fact[m], mod)) % mod;
}
