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

vector <vector <int> > g;
vector <int> used;
vector <int> topsort;

int cycle = 0;

void dfs(int, int);
void dfs2(int);

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) 
        cin >> s[i];
    g.resize(26);
    used.resize(26, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int ki = 0, kj = 0;
            while (s[i][ki] == s[j][kj]) {
                ki++;
                kj++;
                if (ki == s[i].size() || kj == s[j].size())
                    break;
            }
            if (ki == s[i].size() || kj == s[j].size()) {
                if (ki != s[i].size() && kj == s[j].size()) {
                    cout << "Impossible";
                    return 0;
                }
                continue;
            }
            int v = (s[i][ki] - 'a'), u = (s[j][kj] - 'a');
            g[v].push_back(u);
        }
    }
    /*for (int v = 0; v < 26; v++) {
        cout << char('a' + v) << ": ";
        for (auto &u : g[v]) cout << char('a' + u) << " ";
        cout << "\n";
    }*/
    for (int i = 0; i < 26; i++) {
        for (auto &v : g[i]) {
            for (auto &v2 : g[v])
                if (v2 == i) {
                    cout << "Impossible";
                    exit(0);
                }
        }
    }
    for (int i = 0; i < 26; i++)
        if (!used[i]) dfs(i, -1);
    used.clear(); used.resize(26, 0);
    for (int i = 0; i < 26; i++)
        if (!used[i]) dfs2(i);
    reverse(topsort.begin(), topsort.end());
    for (auto &x : topsort)
        cout << char('a' + x);
}

void dfs(int v, int p) {
    used[v] = 1;
    for (auto &u : g[v]) {
        if (!used[u])
            dfs(u, v);
        else if (used[v] == 1 && used[u] == 1) {
            cout << "Impossible";
            exit(0);
        }
    }
    used[v] = 2;
}

void dfs2(int v) {
    used[v] = 1;
    for (auto &u : g[v])
        if (!used[u]) dfs2(u);
    topsort.push_back(v);
}

