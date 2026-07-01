#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n, x, g, s = 0;
        cin >> n;
        cin >> x;
        g = x;
        s += x;
        for (int i = 0; i < n - 1; i++) {
            cin >> x;
            s += x;
            g = __gcd(g, x);
        }
        cout << s << " " << g << "\n";
    }
}