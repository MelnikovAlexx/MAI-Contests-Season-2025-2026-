#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <deque>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

const int inf = 1e9;


vector <vector <int> > used;
int n, m;

void dfs(vector <vector <char> > &, int, int);

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector <vector <char> > f(n, vector <char> (m));
    used.resize(n, vector <int> (m, 0));
    for (auto &x : f)
        for (auto &y : x)
            cin >> y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (f[i][j] != '#' && f[i][j] != '.')
                dfs(f, i, j);
        }
    }
    for (auto &x : f) {
        for (auto &y : x)
            cout << y;
        cout << "\n";
    }
}

void dfs(vector <vector <char> > &f, int i, int j) {
    used[i][j] = 1;
    if (i - 1 >= 0 && f[i - 1][j] == '.') {
        f[i - 1][j] = f[i][j];
        dfs(f, i - 1, j);
    }
    if (j - 1 >= 0 && f[i][j - 1] == '.') {
        f[i][j - 1] = f[i][j];
        dfs(f, i, j - 1);
    }
    if (i + 1 < n && f[i + 1][j] == '.') {
        f[i + 1][j] = f[i][j];
        dfs(f, i + 1, j);
    }
    if (j + 1 < m && f[i][j + 1] == '.') {
        f[i][j + 1] = f[i][j];
        dfs(f, i, j + 1);
    }
}
