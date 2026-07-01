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
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <vector <int> > a(n, vector <int> (m));
        for (auto &x: a)
            for (auto &y: x) cin >> y;
        vector <vector <int> > dp(n, vector <int> (m + 1, 0));
        for (int j = 1; j <= m; j++)
            dp[0][j] = a[0][j - 1];

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 1; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], (max(dp[i - 1][j], dp[i - 1][j - k] + a[i][k - 1])));
                }
            }
        }
        int ans = -1e18;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << "\n";
    }
}
