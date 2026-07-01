#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const long double pi = acos(-1);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (a * c * e != b * d * f) {
        cout << -1;
    }
    else {
        double x = a * f, y = b * f, z = a * e;
        if (x + y + z > 2 * max(x, max(y, z)))
            cout << 1;
        else cout << -1;
    }
}

