#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    long long ans = 0;
    cin >> n;
    vector <long long> a(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = 1e18;
    int i = 0;
    long long mx = 0;
    while (i <= n) {
        int j = i;
        if (a[i] != 1e18)
            mx = max(mx, a[i]);
        while (i < n && a[i] <= a[i + 1]) {
            if (a[i] != 1e18)
                mx = max(mx, a[i]);
            i++;
        }
        if (a[i] != 1e18)
            mx = max(mx, a[i]);
        if (a[i] - a[j] > 1e16) {
            ans += mx - a[j];
        }
        else
            ans += a[i] - a[j];
        i++;
    }
    cout << ans << "\n";
}