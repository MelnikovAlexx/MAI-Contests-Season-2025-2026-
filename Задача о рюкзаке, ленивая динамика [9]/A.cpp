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

#define int long long
#define vll vector <ll>
#define vi vector<int>
#define pii pair <int, int>
#define pll pair <ll, ll>


template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector <vector <int> > a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++)
        {
            int x; cin >> x;
            a[i].push_back(x);
        }
    }
    vector <vector <int> > dp(n);
    dp[0].push_back(a[0][0]);
    for (int i = 1; i < n; i++) {
        dp[i].resize(i + 1);
        for (int j = 0; j < i + 1; j++) dp[i][j] = a[i][j];
        for (int j = 0; j < i + 1; j++) {
            if (j - 1 >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
            if (j <= i - 1)
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
        }
    }
    int mx = -1e18;
    for (int j = 0; j < n; j++)
        mx = max(mx, dp[n - 1][j]);
    cout << mx;
}
