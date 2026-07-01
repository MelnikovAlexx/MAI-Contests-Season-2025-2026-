#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db() cout << "\n===================\n";


const ll MOD = 1e9 + 7, k = 1003;
vector <ll> h, st;


ll add(ll a, ll b) {
    if (a + b > MOD)
        return a + b - MOD;
    return a + b;
}


ll sub(ll a, ll b) {
    if (a - b < 0)
        return a - b + MOD;
    return a - b;
}


ll mul(ll a, ll b) {
    return (ll)a * b % MOD;
}


void buildHash(string &s) {
    int n = s.size();
    h.resize(n + 1, 0);
    st.resize(n + 1);
    st[0] = 1;
    for (int i = 1; i <= n; i++)
        st[i] = mul(st[i - 1], k);
    for (int i = 0; i < n; i++) {
        h[i + 1] = add(mul(h[i], k), s[i]);
    }
}


ll get_hash(int l, int r) {
    return sub(h[r], mul(h[l - 1], st[r - l + 1]));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s, s1;
    cin >> s >> s1;
    buildHash(s);
    int n = s.size();
    set <pair <int, int> > a;
    a.insert(make_pair(h[n], 0));
    for (int i = 0; i < n; i++) {
        a.insert(make_pair(add(get_hash(1, n - i - 1), mul(st[n - i - 1], get_hash(n - i, n))), i + 1));
    }
    int ans;
    buildHash(s1);
    bool fl = false;
    for (auto x: a)
        if (x.first == h[n]) {
            fl = true;
            ans = x.second;
        }
    if (!fl) {
        cout << -1;
        return 0;
    }
    if (s == s1)
        ans = 0;
    cout << ans;
}