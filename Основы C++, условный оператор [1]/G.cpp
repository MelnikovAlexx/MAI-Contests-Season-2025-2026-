#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const double pi = acos(-1);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long n;
    cin >> n;
    vector <long long> dp(n + 100, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 6;
    for (int i = 5; i <= n; i++) {
        dp[i] = i + dp[i - 2];
    }
    cout << dp[n];
}
