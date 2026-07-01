#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    double d, x, y;
    cin >> d >> x >> y;
    double dst = sqrt(x * x + y * y);
    if (d >= dst)
        cout << "YES";
    else cout << "NO";
}
