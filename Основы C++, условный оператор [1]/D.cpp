#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << ((a + c - 1) / c) * ((b + d - 1) / d);
}
