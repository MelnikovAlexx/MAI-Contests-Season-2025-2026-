#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;


bool is_prime(int n) {
    if (n == 1) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    set <int> s;
    map <int, int> d;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
        d[a[i]]++;
    }
    if (s.find(5) != s.end() || s.find(7) != s.end()) {
        cout << -1;
    }
    else {
        if (d[1] != n / 3) cout << -1;
        else {
            vector <string> ans;
            bool fl = true;
            while (true) {
                if (d[1] != 0) {
                    d[1]--;
                    if (d[2] != 0) {
                        d[2]--;
                        if (d[4] != 0) {
                            d[4]--;
                            ans.push_back("1 2 4");
                        }
                        else {
                            if (d[6] != 0) {
                                d[6]--;
                                ans.push_back("1 2 6");
                            }
                        }
                    }
                    else {
                        if (d[3] != 0) {
                            d[3]--;
                            if (d[6] != 0) {
                                d[6]--;
                                ans.push_back("1 3 6");
                            }
                            else {
                                fl = false;
                                break;
                            }
                        }
                        else {
                            fl = false;
                            break;
                        }
                    }
                }
                else {
                    break;
                }
            }
            if (d[1] + d[2] + d[3] + d[4] + d[6] != 0) fl = false;
            if (fl) {
                if (ans.size() == n / 3) {
                    for (auto &x: ans) cout << x << "\n";
                }
                else cout << -1;
            }
            else cout << -1;
        }
    }
}
