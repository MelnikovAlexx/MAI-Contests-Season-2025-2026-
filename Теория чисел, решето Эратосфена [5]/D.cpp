#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;


bool is_prime(int n) {
    if (n == 1) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        bool fl = false;
        cin >> l >> r;
        for (int i = l + (l % 2 == 0); i <= r; i += 2) {
            if (is_prime(i)) {
                cout << i << "\n";
                fl = true;
                break;
            }
        }
        if (!fl) cout << -1 << "\n";
    }
}
