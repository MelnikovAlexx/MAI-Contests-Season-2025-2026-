#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
using namespace std;

#define ll long long
#define vll vector <ll>
#define vi vector<int>
#define pii pair <int, int>
#define pll pair <ll, ll>


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int cnt = 0;
    for (auto &x: s)
    {
        if (x == '0') cnt++;
        if (x == '6' || x == '9' || x == '4') cnt++;
        if (x == '8') cnt += 2;
    }
    cout << cnt;
}

