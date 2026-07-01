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
    map <int, string> d;
    d[1] = "I";
    d[2] = "II";
    d[3] = "III";
    d[4] = "IV";
    d[5] = "V";
    d[6] = "VI";
    d[7] = "VII";
    d[8] = "VIII";
    d[9] = "IX";
    d[10] = "X";
    d[20] = "XX";
    d[30] = "XXX";
    d[40] = "XL";
    d[50] = "L";
    d[60] = "LX";
    d[70] = "LXX";
    d[80] = "LXXX";
    d[90] = "XC";
    d[100] = "C";
    d[200] = "CC";
    d[300] = "CCC";
    d[400] = "CD";
    d[500] = "D";
    d[600] = "DC";
    d[700] = "DCC";
    d[800] = "DCCC";
    d[900] = "CM";
    d[1000] = "M";
    d[2000] = "MM";
    d[3000] = "MMM";
    map <string, int> d2;
    vector <string> all_rim;
    for (int i = 1; i <= 3999; i++) {
        string res = "";
        int tys = i / 1000, sot = (i % 1000) / 100, des = (i % 100) / 10, ed = i % 10;
        if (tys != 0) res += d[tys * 1000];
        if (sot != 0) res += d[sot * 100];
        if (des != 0) res += d[des * 10];
        if (ed != 0) res += d[ed];
        all_rim.push_back(res);
        d2[res] = i;
    }
    sort(all_rim.begin(), all_rim.end());
    int t;
    cin >> t;
    while (t--) {
        string x; cin >> x;
        int nn = d2[x];
        cout << all_rim[nn - 1] << "\n";
    }
}
