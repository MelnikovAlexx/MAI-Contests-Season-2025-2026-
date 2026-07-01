#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    double a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(6) << (a + b) * c;
}
