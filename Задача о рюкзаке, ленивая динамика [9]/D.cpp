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
    int n, w;
    cin >> n >> w;
    vector <pair <int, int>> a(n);
    for (auto &x: a)
        cin >> x.first >> x.second;
    int k = 500 * n;
    vector <int> dp(k + 1, w + 1);
    dp[0] = 0;
    int max_c = -1e9;
    for (int i = 1; i <= n; i++) {
        int weight = a[i - 1].first, cost = a[i - 1].second;
        for (int j = k; j >= cost; j--) {
            if (dp[j - cost] + weight < dp[j]) {
                dp[j] = dp[j - cost] + weight;
            }
        }
    }
    for (int j = 0; j <= k; j++)
        if (dp[j] <= w && j > max_c) max_c = j;
    cout << max_c;
}
