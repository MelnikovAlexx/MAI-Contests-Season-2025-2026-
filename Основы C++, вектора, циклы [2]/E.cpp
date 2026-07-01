#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

const double pi = acos(-1);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int ans = 0, min_x = 1000000, max_x = -1000000, min_y = 1000000, max_y = -1000000;
    for (int i1 = -1000; i1 <= 1000; i1++) {
        for (int j1 = -1000; j1 <= 1000; j1++) {
            if (min(x1, x2) <= i1 && i1 <= max(x1, x2) && min(y1, y2) <= j1 && j1 <= max(y1, y2)) {
                //cout << x3 << " " << y3 << " " << x4 << " " << y4 << "\n";
                if (min(x3, x4) <= i1 && i1 <= max(x3, x4) && min(y4, y3) <= j1 && j1 <= max(y4, y3)) {
                    min_x = min(min_x, i1);
                    max_x = max(max_x, i1);
                    min_y = min(j1, min_y);
                    max_y = max(j1, max_y);
                }
            }
        }
    }
    long long s = abs(x1 - x2) * abs(y1 - y2) + abs(x3 - x4) * abs(y3 - y4);
    if (abs(max_x) > 1000 || abs(min_x) > 1000 || abs(min_y) > 1000 || abs(max_y) > 1000) {
        cout << s;
    }
    else {
        long long s = abs(x1 - x2) * abs(y1 - y2) + abs(x3 - x4) * abs(y3 - y4);
        cout << s - (max_y - min_y) * (max_x - min_x);
    }
}

