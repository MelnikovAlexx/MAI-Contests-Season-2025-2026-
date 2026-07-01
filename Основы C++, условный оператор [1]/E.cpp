#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double dst = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (r1 + r2 >= dst && r1 + dst >= r2 && r2 + dst >= r1)
        cout << "YES";
    else cout << "NO";
}
