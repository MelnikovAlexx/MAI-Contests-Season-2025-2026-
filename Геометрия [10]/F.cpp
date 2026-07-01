#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;


struct Point
{
    int x, y;
};


long long area(Point &a, Point &b)
{
    return (a.x - b.x) * (a.y + b.y);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long ans = 0;
    Point cur, prev, first;
    for (int i = 0; i < n; i++)
    {
        cin >> cur.x >> cur.y;
        if (i > 0)
        {
            ans += area(prev, cur);
        }
        else
            first = cur;
        if (i == n - 1)
            ans += area(cur, first);
        prev = cur;
    }
    cout << fixed << setprecision(1) << fabs(ans / 2.0);
}
