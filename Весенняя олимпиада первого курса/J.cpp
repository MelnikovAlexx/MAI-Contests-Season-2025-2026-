#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int l = 0, r = 0, ans = 0;
    while (r < n) {
        if (a[r] - a[l] <= 5) {
            ans = max(ans, r - l + 1);
            r++;
        }
        else {
            while (a[r] - a[l] > 5) 
                l++;
            ans = max(ans, r - l + 1);
        }
    }
    cout << ans;
}