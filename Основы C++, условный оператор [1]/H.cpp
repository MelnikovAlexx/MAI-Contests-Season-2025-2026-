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
    long double t, c;
    cin >> t >> c;
    if (t < c) cout << 2;
    else cout << 1;
}

