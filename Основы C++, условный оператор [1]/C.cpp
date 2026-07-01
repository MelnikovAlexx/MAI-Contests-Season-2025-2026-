#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int h0, m0, h1, m1, h2, m2, n;
    cin >> h0 >> m0 >> h1 >> m1 >> h2 >> m2 >> n;
    int mm = (h1 * 60 + m1) * n;
    int mm2 = (h2 * 60 + m2) * (n - 1);
    int mm3 = (h0 * 60 + m0) + mm + mm2;
    cout << mm3 / 60 << " " << mm3 % 60;
}
