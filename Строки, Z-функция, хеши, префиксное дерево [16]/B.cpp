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
    string s;
    cin >> s;
    vector <int> p(s.size(), 0);
    for (int i = 1; i < s.size(); i++) {
        int cur = p[i - 1];
        while (s[i] != s[cur] && cur > 0)
            cur = p[cur - 1];
        if (s[i] == s[cur])
            p[i] = cur + 1;
    }
    if (s.size() == 0) {
        cout << 0;
        return 0;
    }
    if (s.size() % (s.size() / (s.size() - p[s.size() - 1])) == 0)
        cout << s.size() / (s.size() / (s.size() - p[s.size() - 1]));
    else
        cout << s.size();
}