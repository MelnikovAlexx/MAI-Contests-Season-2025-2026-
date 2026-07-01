#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

#define int long long

string f(string a, string b) {
    string a_c = a.substr(0, a.find('.'));
    string b_c = b.substr(0, b.find('.'));
    stringstream sx1, sx2;
    string xx;
    int x1, x2;
    sx1 << a_c;
    sx1 >> x1;
    sx1.clear();
    sx2 << b_c;
    sx2 >> x2;
    sx2.clear();
    int rr = x1 + x2;

    a = a.substr(a.find('.') + 1, 15);
    b = b.substr(b.find('.') + 1, 15);
    vector <int> dop(15, 0);
    string rs = "000000000000000";
    for (int i = 14; i >= 0; i--) {
        stringstream sx1, sx2;
        int x1, x2;
        char xx;
        sx1 << a[i];
        sx1 >> x1;
        sx1.clear();
        sx2 << b[i];
        sx2 >> x2;
        sx2.clear();

        int r = x1 + x2 + dop[i];
        if (i - 1 >= 0)
            dop[i - 1] += r / 10;
        else
            rr += (r / 10);
        sx1 << (r % 10);
        sx1 >> xx;
        rs[i] = xx;
    }
    stringstream last;
    last << rr;
    last >> xx;
    last.clear();
    return xx + '.' + rs;
}


signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector <string> a;
    string x;
    while (cin >> x) {
        a.push_back(x);
    }
    string res = a[0];
    for (int i = 1; i < a.size(); i++) {
        res = f(res, a[i]);
    }
    cout << res;
}

