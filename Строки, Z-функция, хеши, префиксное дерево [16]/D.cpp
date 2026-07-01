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
    int ans = 0;
    cin >> s;
    for (int i = s.size() - 1; i > -1; i--) {
        int x = s.size() - i;
        string s1 = s.substr(i, s.size() - i + 1);
        int cur;
        vector <int> p(s1.size(), 0);
        for (int j = 1; j < s1.size(); j++) {
            cur = p[j - 1];
            while (s1[j] != s1[cur] && cur > 0) {
                cur = p[cur - 1];
            }
            if (s1[j] == s1[cur])
                p[j] = cur + 1;
        }
        ans += x - *max_element(p.begin(), p.end());
    }
    cout << ans;
}