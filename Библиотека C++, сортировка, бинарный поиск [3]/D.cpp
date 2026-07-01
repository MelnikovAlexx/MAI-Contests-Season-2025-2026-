#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main() {
    long long n, left, mid, right, x, y;
    cin >> n >> x >> y;
    left = -1;
    n--;
    right = n * max(x, y);
    while (right - left > 1) {
        mid = (right + left) / 2;
        if (mid / x + mid / y >= n)
            right = mid;
        else
            left = mid;
    }
    cout << min(x, y) + right;
}