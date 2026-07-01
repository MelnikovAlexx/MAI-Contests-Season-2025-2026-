#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <numeric>
using namespace std;

const long double pi = acos(-1);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    long double a, h;
    cin >> a >> h;
    cout << fixed << setprecision(10) << 4 * pi * h * h + 6 * pi * h * a + 6 * a * a;
}
