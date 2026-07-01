#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <deque>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

#define int long long
const int inf = 1e9, mod = inf + 7;
int n, m, k, u, v;

vector <vector <int> > g;
vector <int> used;
vector <int> dp;

vector <vector <int> > mult(vector <vector <int> > &, vector <vector <int> > &);
vector <vector <int> > ed(int n);
void print(vector <vector <int> > &);
vector <vector <int> > binpow(vector <vector <int> > &, int, int);
void solve();

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}

void solve() {
    cin >> n >> m >> k;
    vector <vector <int> > g(n, vector <int> (n, 0));
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        g[u][v] = 1;
    }
    g = binpow(g, k, n);
    cout << g[0][0] << "\n";
}

vector <vector <int> > mult(vector <vector <int> > &lhs, vector <vector <int> > &rhs) {
    int n = lhs.size();
    vector <vector <int> > res(n, vector <int> (n));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum = (sum + (lhs[i][j] * rhs[j][k]) % mod) % mod;
            }
            res[i][k] = sum;
        }
    }
    return res;
}

vector <vector <int> > binpow(vector <vector <int> > &arr, int k, int n) {
    if (k == 0) {
        return ed(n);
    }
    if (k == 1) return vector<vector<int>>(arr);
    if (k % 2 == 0) {
        vector <vector <int> > r = binpow(arr, k / 2, n);
        return mult(r, r);
    }
    vector <vector <int> > r = binpow(arr, k - 1, n);
    return mult(arr, r);
}

vector <vector <int> > ed(int n) {
    vector <vector <int> > res(n, vector <int> (n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1;
    return res;
}


void print(vector <vector <int> > &a) {
    for (auto &x : a)
    {
        for (auto &y : x)
            cout << y << " ";
        cout << "\n";
    }
}