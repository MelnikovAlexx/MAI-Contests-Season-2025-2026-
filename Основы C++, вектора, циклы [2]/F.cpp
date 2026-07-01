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
    int n; cin >> n;
    vi a(n); for (auto &x: a) cin >> x;
    vi loc_min, loc_max;
    int i_mn = 1, i_mx = 1, mn = a[0], mx = a[0];
    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0 && a[i - 1] > a[i] && i + 1 < n && a[i] < a[i + 1]) {
            loc_min.push_back(i + 1);
        }
        else {
            if (i - 1 < 0 && i + 1 < n && a[i] < a[i + 1]) {
                loc_min.push_back(i + 1);
            }
            else{
                if (i - 1 >= 0 && i + 1 >= n && a[i] < a[i - 1]) {
                    loc_min.push_back(i + 1);
                }
                else if (i - 1 < 0 && i + 1 >= n) loc_min.push_back(i + 1);
            }
        }



        if (i - 1 >= 0 && a[i - 1] < a[i] && i + 1 < n && a[i] > a[i + 1]) {
            loc_max.push_back(i + 1);
        }
        else {
            if (i - 1 < 0 && i + 1 < n && a[i] > a[i + 1]) {
                loc_max.push_back(i + 1);
            }
            else{
                if (i - 1 >= 0 && i + 1 >= n && a[i] > a[i - 1]) {
                    loc_max.push_back(i + 1);
                }
                else if (i - 1 < 0 && i + 1 >= n) loc_max.push_back(i + 1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] > mx) {
            mx = a[i];
            i_mx = i + 1;
        }
        if (a[i] < mn) {
            mn = a[i];
            i_mn = i + 1;
        }
    }
    sort(loc_min.begin(), loc_min.end());
    sort(loc_max.begin(), loc_max.end());
    cout << loc_min.size() << " ";
    for (auto &x: loc_min) cout << x << " ";
    cout << "\n";
    cout << loc_max.size() << " ";
    for (auto &x: loc_max) cout << x << " ";
    cout << "\n";
    cout << i_mn << " " << i_mx;
}

