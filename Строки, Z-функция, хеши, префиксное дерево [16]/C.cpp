#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db() cout << "\n===================\n";


const ll MOD = 1e9 + 7, k = 1003;
vector <ll> h, rh, st;


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
    rh.resize(n + 1, 0);
    st.resize(n + 1);
    st[0] = 1;
    for (int i = 1; i <= n; i++)
        st[i] = mul(st[i - 1], k);
    for (int i = 0; i < n; i++) {
        h[i + 1] = add(mul(h[i], k), s[i]);
        rh[i + 1] = add(mul(rh[i], k), s[n - i - 1]);
    }
}

ll get_hash(int l, int r) {
    return sub(h[r], mul(h[l - 1], st[r - l + 1]));
}

ll get_rhash(int l, int r) {
    return sub(rh[rh.size() - l], mul(rh[rh.size() - r - 1], st[r - l + 1]));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    int ans = 1;
    cin >> s;
    buildHash(s);
    for (int i = 0; i < s.size(); i++) {
        if (get_hash(1, i + 1) == get_rhash(1, i + 1))
            ans = i + 1;
    }
    cout << ans << "\n";
}